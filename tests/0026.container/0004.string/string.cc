﻿#include <ufio_dsal/string.h>
#include <ufio.h>
#include <algorithm>

int main()
{
	constexpr ::ufio::containers::basic_string_view<char8_t> u8vw(u8"hello world");
	::ufio::u8string str(u8"abcdd");
	::ufio::u8string str3(str);
	str.assign(u8vw);
	::ufio::u8string str2(str);
	::ufio::u8string str4(str3);
	str4 = str2;
	::ufio::u8string str5;
	::ufio::u8string str6, str7;
	str6 = str5;
	str5 = str4;
	str7.assign(u8"hello you");
	::ufio::u8string str8;
	str8.assign_characters(20, u8'b');
	str8.append(str7);
	str8.append(str8); // self append
	::ufio::u8string str9;
	str9.append(str9); // self append for empty string
	str9.append(str7);
	str9.append(::ufio::u8concat_ufio(u8"concat:", str9.size(), u8"\tok"));
	constexpr ::ufio::containers::basic_cstring_view<char8_t> u8cstrvw(u8"hello c_str");
	::ufio::u8string str10(u8cstrvw);
	constexpr char8_t const *oldstylecstr{u8"old style char8_t coonst* ptr"};
	::ufio::u8string str11(::ufio::mnp::os_c_str(oldstylecstr));
	str11.insert_index(4, u8"stupid ");
	str11.insert_index(4, u8"shit ");
	auto str12(str11.substr_front(3));
	auto str13(str11.substr_back(3));
	auto str14(str11.substr(4,11));
	auto str15{str14},str16{str14};
	str15.erase_index(3,5);
	str16.remove_suffix(3);
	auto str17(str9),str18(str16);
	::ufio::u8string str19;
	::std::ranges::swap(str17,str18);
	::std::ranges::swap(str19,str19);
	::std::ranges::swap(str19,str18);
	auto str20(str16);
	str20.erase_index(1,3);
	str20.resize_and_overwrite(40,[](char8_t* buf, ::std::size_t n) noexcept
	{
		return static_cast<::std::size_t>(::std::fill_n(buf, n, u8'z') - buf);
	});
	auto str21(str20);
	str21.replace_index(0,10, u8"helloworld");
	str21.replace_index(38,40, str21.subview_front(10));
	::ufio::io::println(
		::ufio::u8c_stdout(),
		u8"u8vw=", u8vw,
		u8"\nstr=", str,
		u8"\nstr2=", str2,
		u8"\nstr3=", str3,
		u8"\nstr4=", str4,
		u8"\nstr5=", str5,
		u8"\nstr6=", str6,
		u8"\nstr7=", str7,
		u8"\nstr8=", str8,
		u8"\nstr9=", str9,
		u8"\nstr10=", str10,
		u8"\nstr11=", str11,
		u8"\nstr12=", str12,
		u8"\nstr13=", str13,
		u8"\nstr14=", str14,
		u8"\nstr15=", str15,
		u8"\nstr16=", str16,
		u8"\nstr17(str9)=", str17,
		u8"\nstr18(str16)=", str18,
		u8"\nstr19=", str19,
		u8"\nstr20=", str20,
		u8"\nstr21=", str21,
		u8"\nstr4==str5:",str4==str5,
		u8"\nstr10<=>str14:",str10<=>str14,
		u8"\nstr4==u8\"hello world\":",str4==u8"hello world",
		u8"\nstr11<=>u8\"hello world\":",str11==u8"hello world",
		u8"\nstr4==u8cstrvw:",str4==u8cstrvw,
		u8"\nstr10<=>u8cstrvw:",str10<=>u8cstrvw);
}