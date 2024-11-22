#pragma once

namespace ufio
{
template <typename T, typename Mutex>
	requires requires(Mutex &&m) {
		m.lock();
		m.unlock();
		m.try_lock();
	}
struct basic_general_io_lockable_nonmovable
{
	using mutex_type = Mutex;
	using unlocked_handle_type = T;
#ifndef __INTELLISENSE__
#if __has_cpp_attribute(msvc::no_unique_address)
	[[msvc::no_unique_address]]
#elif __has_cpp_attribute(no_unique_address) >= 201803
	[[no_unique_address]]
#endif
#endif
	T handle;
#ifndef __INTELLISENSE__
#if __has_cpp_attribute(msvc::no_unique_address)
	[[msvc::no_unique_address]]
#elif __has_cpp_attribute(no_unique_address) >= 201803
	[[no_unique_address]]
#endif
#endif
	mutex_type mutex;

	template <typename... Args>
		requires ::std::constructible_from<T, Args...>
	explicit constexpr basic_general_io_lockable_nonmovable(Args &&...args)
		: handle(::std::forward<Args>(args)...)
	{
	}

	template <typename... Args>
		requires(::std::constructible_from<T, Args...>)
	constexpr void reopen(Args &&...args)
	{
		::ufio::io_lock_guard guard(mutex);
		if constexpr (requires() {
						  handle.reopen(::std::forward<Args>(args)...);
					  })
		{
			handle.reopen(::std::forward<Args>(args)...);
		}
		else
		{
			this->handle = T(::std::forward<Args>(args)...);
		}
	}
	constexpr void close() noexcept(noexcept(handle.close()))
	{
		::ufio::io_lock_guard guard(mutex);
		handle.close();
	}
};

namespace details
{

template <typename T, typename Allocator>
struct heap_allocate_guard
{
	using value_type = T;
	using native_handle_type = T *;
	using allocator_type = Allocator;
	using typed_allocator_type = ::ufio::typed_generic_allocator_adapter<allocator_type, value_type>;
	native_handle_type ptr;
	explicit constexpr heap_allocate_guard() noexcept
		: ptr{typed_allocator_type::allocate(1)}
	{
	}
	heap_allocate_guard(heap_allocate_guard const &) = delete;
	heap_allocate_guard &operator=(heap_allocate_guard const &) = delete;
	constexpr native_handle_type release() noexcept
	{
		auto temp{this->ptr};
		this->ptr = nullptr;
		return temp;
	}
	constexpr ~heap_allocate_guard()
	{
		typed_allocator_type::deallocate_n(ptr, 1);
	}
};

} // namespace details

template <typename T, typename Mutex>
struct basic_general_io_lockable_ref
{
	using input_char_type = typename T::input_char_type;
	using output_char_type = typename T::output_char_type;
	using native_handle_type = basic_general_io_lockable_nonmovable<T, Mutex> *;
	native_handle_type ptr{};
};

template <typename T, typename Mutex>
	requires ::ufio::operations::defines::has_output_or_io_stream_ref_define<T>
inline constexpr basic_general_io_lockable_ref<T, Mutex>
output_stream_ref_define(::ufio::basic_general_io_lockable_nonmovable<T, Mutex> &m) noexcept
{
	return {__builtin_addressof(m)};
}

template <typename T, typename Mutex>
	requires ::ufio::operations::defines::has_input_or_io_stream_ref_define<T>
inline constexpr basic_general_io_lockable_ref<T, Mutex>
input_stream_ref_define(::ufio::basic_general_io_lockable_nonmovable<T, Mutex> &m) noexcept
{
	return {__builtin_addressof(m)};
}

template <typename T, typename Mutex>
	requires ::ufio::operations::defines::has_io_stream_ref_define<T>
inline constexpr basic_general_io_lockable_ref<T, Mutex> io_stream_ref_define(::ufio::basic_general_io_lockable_nonmovable<T, Mutex> &m) noexcept
{
	return {__builtin_addressof(m)};
}

template <typename Mutex, typename Allocator>
	requires ::std::default_initializable<Mutex>
struct basic_general_mutex_movable
{
	using mutex_type = Mutex;
	using allocator_type = Allocator;
	using native_handle_type = mutex_type *;
	mutex_type *pmutex{};

private:
	constexpr void construct_default() noexcept(::std::is_nothrow_default_constructible_v<mutex_type>)
	{
		::ufio::details::heap_allocate_guard<mutex_type, allocator_type> g;
		::std::construct_at(g.ptr);
		this->pmutex = g.release();
	}

public:
	explicit constexpr basic_general_mutex_movable() noexcept(::std::is_nothrow_default_constructible_v<mutex_type>)
	{
		this->construct_default();
	}

	explicit constexpr basic_general_mutex_movable(::ufio::for_overwrite_t) noexcept
	{
	}

private:
	constexpr void destroy() noexcept
	{
		if (pmutex)
		{
			::std::destroy_at(this->pmutex);
			::ufio::typed_generic_allocator_adapter<allocator_type, mutex_type>::deallocate_n(pmutex, 1);
		}
	}

public:
	constexpr void close() noexcept
	{
		this->destroy();
		this->pmutex = nullptr;
	}
	constexpr void reopen() noexcept(::std::is_nothrow_default_constructible_v<mutex_type>)
	{
		this->close();
		this->construct_default();
	}

	constexpr native_handle_type release() noexcept
	{
		auto temp{this->pmutex};
		this->pmutex = nullptr;
		return temp;
	}

	basic_general_mutex_movable(basic_general_mutex_movable const &) = delete;
	basic_general_mutex_movable &operator=(basic_general_mutex_movable const &) = delete;
	constexpr basic_general_mutex_movable(basic_general_mutex_movable &&other) noexcept
		: pmutex{other.pmutex}
	{
		other.pmutex = nullptr;
	}
	constexpr basic_general_mutex_movable &operator=(basic_general_mutex_movable &&other) noexcept
	{
		if (__builtin_addressof(other) == this)
		{
			return *this;
		}
		other.destroy();
		this->pmutex = other.pmutex;
		other.pmutex = nullptr;
		return *this;
	}

	constexpr ~basic_general_mutex_movable()
	{
		this->destroy();
	}
	inline constexpr void lock() noexcept(noexcept(pmutex->lock()))
	{
		pmutex->lock();
	}
	inline constexpr bool try_lock() noexcept(noexcept(pmutex->try_lock()))
	{
		return pmutex->try_lock();
	}
	inline constexpr void unlock() noexcept
	{
		pmutex->unlock();
	}
	inline constexpr native_handle_type native_handle() const noexcept
	{
		return pmutex;
	}
};

template <typename Mutex>
struct basic_mutex_ref
{
	using mutex_type = Mutex;
	using native_handle_type = mutex_type *;
	mutex_type *pmutex{};
	inline constexpr void lock() noexcept(noexcept(pmutex->lock()))
	{
		pmutex->lock();
	}
	inline constexpr bool try_lock() noexcept(noexcept(pmutex->try_lock()))
	{
		return pmutex->try_lock();
	}
	inline constexpr void unlock() noexcept
	{
		pmutex->unlock();
	}
	inline constexpr native_handle_type native_handle() const noexcept
	{
		return pmutex;
	}
};

template <typename Mutex, typename Allocator>
inline constexpr ::ufio::basic_mutex_ref<Mutex> mutex_ref_define(::ufio::basic_general_mutex_movable<Mutex, Allocator> &mtx) noexcept
{
	return {mtx.pmutex};
}

namespace operations::defines
{

template <typename T>
concept has_mutex_ref_define = requires(T t) {
	mutex_ref_define(t);
};

} // namespace operations::defines

template <typename T, typename Mutex>
inline constexpr decltype(auto) io_stream_mutex_ref_define(::ufio::basic_general_io_lockable_ref<T, Mutex> mtx)
{
	if constexpr (::ufio::operations::defines::has_mutex_ref_define<Mutex>)
	{
		return mutex_ref_define(mtx.ptr->mutex);
	}
	else
	{
		return ::ufio::basic_mutex_ref<Mutex>{__builtin_addressof(mtx.ptr->mutex)};
	}
}

template <typename T, typename Mutex>
	requires ::ufio::operations::defines::has_output_stream_ref_define<T>
inline constexpr decltype(auto) output_stream_unlocked_ref_define(::ufio::basic_general_io_lockable_ref<T, Mutex> mtx)
{
	return output_stream_ref_define(mtx.ptr->handle);
}

template <typename T, typename Mutex>
	requires ::ufio::operations::defines::has_input_stream_ref_define<T>
inline constexpr decltype(auto) input_stream_unlocked_ref_define(::ufio::basic_general_io_lockable_ref<T, Mutex> mtx)
{
	return input_stream_ref_define(mtx.ptr->handle);
}

template <typename T, typename Mutex>
	requires ::ufio::operations::defines::has_io_stream_ref_define<T>
inline constexpr decltype(auto) io_stream_unlocked_ref_define(::ufio::basic_general_io_lockable_ref<T, Mutex> mtx)
{
	return io_stream_ref_define(mtx.ptr->handle);
}

} // namespace ufio
