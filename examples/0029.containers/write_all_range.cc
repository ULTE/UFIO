#include <ufio.h>
#include <ufio_device.h>
#include <deque>
#include <vector>
#include <forward_list>

int main()
{
	{
		::std::deque<::std::size_t> deq{1, 2, 3, 4, 5, 6, 7, 8};
		::ufio::obuf_file obf("rangedeq.txt");
		::ufio::operations::write_all_range(obf, deq);
	}
	{
		::std::vector<::std::size_t> vec{1, 2, 3, 4, 5, 6, 7, 8};
		::ufio::obuf_file obf("rangevec.txt");
		::ufio::operations::write_all_range(obf, vec);
	}
	{
		::std::forward_list<::std::size_t> fwdlst{1, 2, 3, 4, 5, 6, 7, 8};
		::ufio::obuf_file obf("rangefwdlst.txt");
		::ufio::operations::write_all_range(obf, fwdlst);
	}
}
