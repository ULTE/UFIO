#include <ufio.h>

struct decofiltest
{
	using input_char_type = char;
	using output_char_type = char;
	static inline constexpr ::std::size_t remained_max = 5u;
	static inline constexpr ::std::size_t output_final_max = 5u;
	static inline constexpr ::ufio::deco_result<char, char> process_chars(input_char_type const *fromfirst, input_char_type const *fromlast,
																			 output_char_type *tofirst, output_char_type *tolast) noexcept
	{
		::std::size_t diff{static_cast<::std::size_t>(fromlast - fromfirst)};
		::std::size_t todiff{static_cast<::std::size_t>(tolast - tofirst)};
		if (todiff < diff)
		{
			diff = todiff;
		}
		::ufio::details::non_overlapped_copy_n(fromfirst, diff, tofirst);
		return {fromfirst + diff, tofirst + diff};
	}
};
using decofilttest_decorator = ::ufio::deco_partial_adapter<decofiltest>;
using bidecorator = ::ufio::basic_bidirectional_decorator_adaptor<decofilttest_decorator, decofilttest_decorator>;

int main()
{
	constexpr std::size_t N(10000000);
	::ufio::iobuf_io_file obf(::ufio::io_cookie_type<::ufio::native_file>, u8"io_file_deco.txt", ::ufio::open_mode::out);

	::ufio::operations::add_io_decos(obf, bidecorator{});
	for (std::size_t i{}; i != N; ++i)
	{
		::ufio::io::println(obf, i);
	}
}
