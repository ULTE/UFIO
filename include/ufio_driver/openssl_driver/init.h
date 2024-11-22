#pragma once

namespace ufio
{

class global_initializer
{
public:
	explicit global_initializer() noexcept
	{
		SSL_library_init();
	}
};

} // namespace ufio