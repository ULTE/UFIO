#include <ufio_legacy.h>

struct my_custom_type
{};

inline std::ostream &operator<<(std::ostream &out, my_custom_type)
{
	return out << "custom type";
}

using namespace ufio::io;

int main()
{
	my_custom_type m;
	println(ufio::mnp::operator_output(m));
}
