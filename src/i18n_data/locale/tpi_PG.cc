﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("tpi_PG"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Tok Pisin language locale for Papua New Guinea"),.source=tsc("Samsung Electronics Co., Ltd.\t\t;\t\tufio"),.address=tsc("https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Tok Pisin"),.territory=tsc("Papua New Guinea"),.revision=tsc("0.1"),.date=tsc("2017-03-21")},.monetary={.int_curr_symbol=tsc("PGK "),.currency_symbol=tsc("K"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.int_p_sep_by_space=1,.int_n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("San"),tsc("Man"),tsc("Tun"),tsc("Tri"),tsc("Fon"),tsc("Fra"),tsc("Sar")},.day={tsc("Sande"),tsc("Mande"),tsc("Tunde"),tsc("Trinde"),tsc("Fonde"),tsc("Fraide"),tsc("Sarere")},.abmon={tsc("Jan"),tsc("Feb"),tsc("Mas"),tsc("Epr"),tsc("Me"),tsc("Jun"),tsc("Jul"),tsc("Oga"),tsc("Sep"),tsc("Okt"),tsc("Nov"),tsc("Des")},.mon={tsc("Janueri"),tsc("Februeri"),tsc("Mas"),tsc("Epril"),tsc("Me"),tsc("Jun"),tsc("Julai"),tsc("Ogas"),tsc("Septemba"),tsc("Oktoba"),tsc("Novemba"),tsc("Desemba")},.d_t_fmt=tsc("%a %d %b %Y %T"),.d_fmt=tsc("%d//%m//%Y"),.t_fmt=tsc("%r"),.t_fmt_ampm=tsc("%I:%M:%S %p %Z"),.date_fmt=tsc("%a %d %b %Y %T %Z"),.am_pm={tsc("biknait"),tsc("apinun")},.week={7,19971130,1}},.messages={.yesexpr=tsc("^[+1yY]"),.noexpr=tsc("^[-0nN]"),.yesstr=tsc("yes"),.nostr=tsc("nogat")},.paper={.width=210,.height=297},.telephone={.int_select=tsc("00"),.int_prefix=tsc("675")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f"),.name_miss=tsc("Miss."),.name_mr=tsc("Mr."),.name_mrs=tsc("Mrs."),.name_ms=tsc("Ms.")},.address={.country_name=tsc("Papua Niugini"),.country_post=tsc(""),.country_ab2=tsc("PG"),.country_ab3=tsc("PNG"),.country_num=598,.country_car=tsc("PNG"),.lang_name=tsc("Tok Pisin"),.lang_ab=tsc(""),.lang_term=tsc("tpi"),.lang_lib=tsc("tpi")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"tpi_PG"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Tok Pisin language locale for Papua New Guinea"),.source=tsc(L"Samsung Electronics Co., Ltd.\t\t;\t\tufio"),.address=tsc(L"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Tok Pisin"),.territory=tsc(L"Papua New Guinea"),.revision=tsc(L"0.1"),.date=tsc(L"2017-03-21")},.monetary={.int_curr_symbol=tsc(L"PGK "),.currency_symbol=tsc(L"K"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.int_p_sep_by_space=1,.int_n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"San"),tsc(L"Man"),tsc(L"Tun"),tsc(L"Tri"),tsc(L"Fon"),tsc(L"Fra"),tsc(L"Sar")},.day={tsc(L"Sande"),tsc(L"Mande"),tsc(L"Tunde"),tsc(L"Trinde"),tsc(L"Fonde"),tsc(L"Fraide"),tsc(L"Sarere")},.abmon={tsc(L"Jan"),tsc(L"Feb"),tsc(L"Mas"),tsc(L"Epr"),tsc(L"Me"),tsc(L"Jun"),tsc(L"Jul"),tsc(L"Oga"),tsc(L"Sep"),tsc(L"Okt"),tsc(L"Nov"),tsc(L"Des")},.mon={tsc(L"Janueri"),tsc(L"Februeri"),tsc(L"Mas"),tsc(L"Epril"),tsc(L"Me"),tsc(L"Jun"),tsc(L"Julai"),tsc(L"Ogas"),tsc(L"Septemba"),tsc(L"Oktoba"),tsc(L"Novemba"),tsc(L"Desemba")},.d_t_fmt=tsc(L"%a %d %b %Y %T"),.d_fmt=tsc(L"%d//%m//%Y"),.t_fmt=tsc(L"%r"),.t_fmt_ampm=tsc(L"%I:%M:%S %p %Z"),.date_fmt=tsc(L"%a %d %b %Y %T %Z"),.am_pm={tsc(L"biknait"),tsc(L"apinun")},.week={7,19971130,1}},.messages={.yesexpr=tsc(L"^[+1yY]"),.noexpr=tsc(L"^[-0nN]"),.yesstr=tsc(L"yes"),.nostr=tsc(L"nogat")},.paper={.width=210,.height=297},.telephone={.int_select=tsc(L"00"),.int_prefix=tsc(L"675")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f"),.name_miss=tsc(L"Miss."),.name_mr=tsc(L"Mr."),.name_mrs=tsc(L"Mrs."),.name_ms=tsc(L"Ms.")},.address={.country_name=tsc(L"Papua Niugini"),.country_post=tsc(L""),.country_ab2=tsc(L"PG"),.country_ab3=tsc(L"PNG"),.country_num=598,.country_car=tsc(L"PNG"),.lang_name=tsc(L"Tok Pisin"),.lang_ab=tsc(L""),.lang_term=tsc(L"tpi"),.lang_lib=tsc(L"tpi")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"tpi_PG"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Tok Pisin language locale for Papua New Guinea"),.source=tsc(u8"Samsung Electronics Co., Ltd.\t\t;\t\tufio"),.address=tsc(u8"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Tok Pisin"),.territory=tsc(u8"Papua New Guinea"),.revision=tsc(u8"0.1"),.date=tsc(u8"2017-03-21")},.monetary={.int_curr_symbol=tsc(u8"PGK "),.currency_symbol=tsc(u8"K"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.int_p_sep_by_space=1,.int_n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"San"),tsc(u8"Man"),tsc(u8"Tun"),tsc(u8"Tri"),tsc(u8"Fon"),tsc(u8"Fra"),tsc(u8"Sar")},.day={tsc(u8"Sande"),tsc(u8"Mande"),tsc(u8"Tunde"),tsc(u8"Trinde"),tsc(u8"Fonde"),tsc(u8"Fraide"),tsc(u8"Sarere")},.abmon={tsc(u8"Jan"),tsc(u8"Feb"),tsc(u8"Mas"),tsc(u8"Epr"),tsc(u8"Me"),tsc(u8"Jun"),tsc(u8"Jul"),tsc(u8"Oga"),tsc(u8"Sep"),tsc(u8"Okt"),tsc(u8"Nov"),tsc(u8"Des")},.mon={tsc(u8"Janueri"),tsc(u8"Februeri"),tsc(u8"Mas"),tsc(u8"Epril"),tsc(u8"Me"),tsc(u8"Jun"),tsc(u8"Julai"),tsc(u8"Ogas"),tsc(u8"Septemba"),tsc(u8"Oktoba"),tsc(u8"Novemba"),tsc(u8"Desemba")},.d_t_fmt=tsc(u8"%a %d %b %Y %T"),.d_fmt=tsc(u8"%d//%m//%Y"),.t_fmt=tsc(u8"%r"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p %Z"),.date_fmt=tsc(u8"%a %d %b %Y %T %Z"),.am_pm={tsc(u8"biknait"),tsc(u8"apinun")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u8"^[+1yY]"),.noexpr=tsc(u8"^[-0nN]"),.yesstr=tsc(u8"yes"),.nostr=tsc(u8"nogat")},.paper={.width=210,.height=297},.telephone={.int_select=tsc(u8"00"),.int_prefix=tsc(u8"675")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f"),.name_miss=tsc(u8"Miss."),.name_mr=tsc(u8"Mr."),.name_mrs=tsc(u8"Mrs."),.name_ms=tsc(u8"Ms.")},.address={.country_name=tsc(u8"Papua Niugini"),.country_post=tsc(u8""),.country_ab2=tsc(u8"PG"),.country_ab3=tsc(u8"PNG"),.country_num=598,.country_car=tsc(u8"PNG"),.lang_name=tsc(u8"Tok Pisin"),.lang_ab=tsc(u8""),.lang_term=tsc(u8"tpi"),.lang_lib=tsc(u8"tpi")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"tpi_PG"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Tok Pisin language locale for Papua New Guinea"),.source=tsc(u"Samsung Electronics Co., Ltd.\t\t;\t\tufio"),.address=tsc(u"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Tok Pisin"),.territory=tsc(u"Papua New Guinea"),.revision=tsc(u"0.1"),.date=tsc(u"2017-03-21")},.monetary={.int_curr_symbol=tsc(u"PGK "),.currency_symbol=tsc(u"K"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.int_p_sep_by_space=1,.int_n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"San"),tsc(u"Man"),tsc(u"Tun"),tsc(u"Tri"),tsc(u"Fon"),tsc(u"Fra"),tsc(u"Sar")},.day={tsc(u"Sande"),tsc(u"Mande"),tsc(u"Tunde"),tsc(u"Trinde"),tsc(u"Fonde"),tsc(u"Fraide"),tsc(u"Sarere")},.abmon={tsc(u"Jan"),tsc(u"Feb"),tsc(u"Mas"),tsc(u"Epr"),tsc(u"Me"),tsc(u"Jun"),tsc(u"Jul"),tsc(u"Oga"),tsc(u"Sep"),tsc(u"Okt"),tsc(u"Nov"),tsc(u"Des")},.mon={tsc(u"Janueri"),tsc(u"Februeri"),tsc(u"Mas"),tsc(u"Epril"),tsc(u"Me"),tsc(u"Jun"),tsc(u"Julai"),tsc(u"Ogas"),tsc(u"Septemba"),tsc(u"Oktoba"),tsc(u"Novemba"),tsc(u"Desemba")},.d_t_fmt=tsc(u"%a %d %b %Y %T"),.d_fmt=tsc(u"%d//%m//%Y"),.t_fmt=tsc(u"%r"),.t_fmt_ampm=tsc(u"%I:%M:%S %p %Z"),.date_fmt=tsc(u"%a %d %b %Y %T %Z"),.am_pm={tsc(u"biknait"),tsc(u"apinun")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u"^[+1yY]"),.noexpr=tsc(u"^[-0nN]"),.yesstr=tsc(u"yes"),.nostr=tsc(u"nogat")},.paper={.width=210,.height=297},.telephone={.int_select=tsc(u"00"),.int_prefix=tsc(u"675")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f"),.name_miss=tsc(u"Miss."),.name_mr=tsc(u"Mr."),.name_mrs=tsc(u"Mrs."),.name_ms=tsc(u"Ms.")},.address={.country_name=tsc(u"Papua Niugini"),.country_post=tsc(u""),.country_ab2=tsc(u"PG"),.country_ab3=tsc(u"PNG"),.country_num=598,.country_car=tsc(u"PNG"),.lang_name=tsc(u"Tok Pisin"),.lang_ab=tsc(u""),.lang_term=tsc(u"tpi"),.lang_lib=tsc(u"tpi")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"tpi_PG"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Tok Pisin language locale for Papua New Guinea"),.source=tsc(U"Samsung Electronics Co., Ltd.\t\t;\t\tufio"),.address=tsc(U"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Tok Pisin"),.territory=tsc(U"Papua New Guinea"),.revision=tsc(U"0.1"),.date=tsc(U"2017-03-21")},.monetary={.int_curr_symbol=tsc(U"PGK "),.currency_symbol=tsc(U"K"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.int_p_sep_by_space=1,.int_n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"San"),tsc(U"Man"),tsc(U"Tun"),tsc(U"Tri"),tsc(U"Fon"),tsc(U"Fra"),tsc(U"Sar")},.day={tsc(U"Sande"),tsc(U"Mande"),tsc(U"Tunde"),tsc(U"Trinde"),tsc(U"Fonde"),tsc(U"Fraide"),tsc(U"Sarere")},.abmon={tsc(U"Jan"),tsc(U"Feb"),tsc(U"Mas"),tsc(U"Epr"),tsc(U"Me"),tsc(U"Jun"),tsc(U"Jul"),tsc(U"Oga"),tsc(U"Sep"),tsc(U"Okt"),tsc(U"Nov"),tsc(U"Des")},.mon={tsc(U"Janueri"),tsc(U"Februeri"),tsc(U"Mas"),tsc(U"Epril"),tsc(U"Me"),tsc(U"Jun"),tsc(U"Julai"),tsc(U"Ogas"),tsc(U"Septemba"),tsc(U"Oktoba"),tsc(U"Novemba"),tsc(U"Desemba")},.d_t_fmt=tsc(U"%a %d %b %Y %T"),.d_fmt=tsc(U"%d//%m//%Y"),.t_fmt=tsc(U"%r"),.t_fmt_ampm=tsc(U"%I:%M:%S %p %Z"),.date_fmt=tsc(U"%a %d %b %Y %T %Z"),.am_pm={tsc(U"biknait"),tsc(U"apinun")},.week={7,19971130,1}},.messages={.yesexpr=tsc(U"^[+1yY]"),.noexpr=tsc(U"^[-0nN]"),.yesstr=tsc(U"yes"),.nostr=tsc(U"nogat")},.paper={.width=210,.height=297},.telephone={.int_select=tsc(U"00"),.int_prefix=tsc(U"675")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f"),.name_miss=tsc(U"Miss."),.name_mr=tsc(U"Mr."),.name_mrs=tsc(U"Mrs."),.name_ms=tsc(U"Ms.")},.address={.country_name=tsc(U"Papua Niugini"),.country_post=tsc(U""),.country_ab2=tsc(U"PG"),.country_ab3=tsc(U"PNG"),.country_num=598,.country_car=tsc(U"PNG"),.lang_name=tsc(U"Tok Pisin"),.lang_ab=tsc(U""),.lang_term=tsc(U"tpi"),.lang_lib=tsc(U"tpi")},.measurement={.measurement=1}};


}
}

#include"../main.h"