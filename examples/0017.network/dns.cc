#include <ufio.h>

using namespace ufio::io;

int main(int argc, char const **argv)
{
	if (argc < 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", ::ufio::mnp::os_c_str(*argv), " <domain>\n");
		return 1;
	}
	ufio::net_service service;
	ufio::native_dns_file dnsfile;
	try
	{
		dnsfile = ufio::native_dns_file(::ufio::mnp::os_c_str(argv[1]));
	}
	catch (::ufio::error e)
	{
		::ufio::io::perrln(e);
		return -1;
	}
	for (auto ent : dnsfile)
	{
		println(to_ip_address(ent));
	}
}
