#include <ufio_dsal/string.h>
#include <cstdint>
#include <ufio.h>

using String = ::ufio::string;

struct Employee
{
	String title;
	::std::int64_t salary;
	String firstname;
	String lastname;
	auto const &Title() const noexcept
	{
		return title;
	}
	auto const &Salary() const noexcept
	{
		return salary;
	}
	auto const &First() const noexcept
	{
		return firstname;
	}
	auto const &Last() const noexcept
	{
		return lastname;
	}
};

String EvaluateSalaryAndReturnName(Employee e)
{
	if (e.Title() == "CEO" || e.Salary() > 100000)
	{
		::ufio::io::print(e.First(), " ", e.Last(),
							" is overpaid\n");
	}
	return ::ufio::concat_ufio(e.First(), " ", e.Last());
}

int main()
{
}
