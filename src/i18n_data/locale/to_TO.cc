﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("to_TO"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Tongan language locale for Tonga"),.source=tsc("International Components for Unicode\t\t;\t\tufio"),.address=tsc("Samsung R & D Institute India - Delhi 2-A Sectort 126 Noida 201303\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Tongan"),.territory=tsc("Tonga"),.revision=tsc("1.0"),.date=tsc("2017-03-23")},.monetary={.int_curr_symbol=tsc("TOP "),.currency_symbol=tsc("T$"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("Sāp"),tsc("Mōn"),tsc("Tūs"),tsc("Pul"),tsc("Tuʻa"),tsc("Fal"),tsc("Tok")},.day={tsc("Sāpate"),tsc("Mōnite"),tsc("Tūsite"),tsc("Pulelulu"),tsc("Tuʻapulelulu"),tsc("Falaite"),tsc("Tokonaki")},.abmon={tsc("Sān"),tsc("Fēp"),tsc("Maʻa"),tsc("ʻEpe"),tsc("Mē"),tsc("Sun"),tsc("Siu"),tsc("ʻAok"),tsc("Sep"),tsc("ʻOka"),tsc("Nōv"),tsc("Tīs")},.mon={tsc("Sānuali"),tsc("Fēpueli"),tsc("Maʻasi"),tsc("ʻEpeleli"),tsc("Mē"),tsc("Sune"),tsc("Siulai"),tsc("ʻAokosi"),tsc("Sepitema"),tsc("ʻOkatopa"),tsc("Nōvema"),tsc("Tīsema")},.d_t_fmt=tsc("%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc("%A %d %b %Y"),.t_fmt=tsc("%I:%M:%S %p %Z"),.t_fmt_ampm=tsc("%I:%M:%S %p %Z"),.date_fmt=tsc("%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc("hengihengi"),tsc("efiafi")}},.messages={.yesexpr=tsc("^[+1yY]"),.noexpr=tsc("^[-0nN]"),.yesstr=tsc("ʻIo"),.nostr=tsc("ʻIkai")},.paper={.width=210,.height=297},.telephone={.int_select=tsc("00"),.int_prefix=tsc("676")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f"),.name_miss=tsc("Miss."),.name_mr=tsc("Mr."),.name_mrs=tsc("Mrs."),.name_ms=tsc("Ms.")},.address={.postal_fmt=tsc("%a%b%s%c"),.country_name=tsc("Tonga"),.country_post=tsc(""),.country_ab2=tsc("TO"),.country_ab3=tsc("TON"),.country_num=776,.country_car=tsc("TON"),.lang_name=tsc("lea fakatonga"),.lang_ab=tsc("to"),.lang_term=tsc("ton"),.lang_lib=tsc("ton")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"to_TO"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Tongan language locale for Tonga"),.source=tsc(L"International Components for Unicode\t\t;\t\tufio"),.address=tsc(L"Samsung R & D Institute India - Delhi 2-A Sectort 126 Noida 201303\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Tongan"),.territory=tsc(L"Tonga"),.revision=tsc(L"1.0"),.date=tsc(L"2017-03-23")},.monetary={.int_curr_symbol=tsc(L"TOP "),.currency_symbol=tsc(L"T$"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"Sāp"),tsc(L"Mōn"),tsc(L"Tūs"),tsc(L"Pul"),tsc(L"Tuʻa"),tsc(L"Fal"),tsc(L"Tok")},.day={tsc(L"Sāpate"),tsc(L"Mōnite"),tsc(L"Tūsite"),tsc(L"Pulelulu"),tsc(L"Tuʻapulelulu"),tsc(L"Falaite"),tsc(L"Tokonaki")},.abmon={tsc(L"Sān"),tsc(L"Fēp"),tsc(L"Maʻa"),tsc(L"ʻEpe"),tsc(L"Mē"),tsc(L"Sun"),tsc(L"Siu"),tsc(L"ʻAok"),tsc(L"Sep"),tsc(L"ʻOka"),tsc(L"Nōv"),tsc(L"Tīs")},.mon={tsc(L"Sānuali"),tsc(L"Fēpueli"),tsc(L"Maʻasi"),tsc(L"ʻEpeleli"),tsc(L"Mē"),tsc(L"Sune"),tsc(L"Siulai"),tsc(L"ʻAokosi"),tsc(L"Sepitema"),tsc(L"ʻOkatopa"),tsc(L"Nōvema"),tsc(L"Tīsema")},.d_t_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(L"%A %d %b %Y"),.t_fmt=tsc(L"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(L"%I:%M:%S %p %Z"),.date_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(L"hengihengi"),tsc(L"efiafi")}},.messages={.yesexpr=tsc(L"^[+1yY]"),.noexpr=tsc(L"^[-0nN]"),.yesstr=tsc(L"ʻIo"),.nostr=tsc(L"ʻIkai")},.paper={.width=210,.height=297},.telephone={.int_select=tsc(L"00"),.int_prefix=tsc(L"676")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f"),.name_miss=tsc(L"Miss."),.name_mr=tsc(L"Mr."),.name_mrs=tsc(L"Mrs."),.name_ms=tsc(L"Ms.")},.address={.postal_fmt=tsc(L"%a%b%s%c"),.country_name=tsc(L"Tonga"),.country_post=tsc(L""),.country_ab2=tsc(L"TO"),.country_ab3=tsc(L"TON"),.country_num=776,.country_car=tsc(L"TON"),.lang_name=tsc(L"lea fakatonga"),.lang_ab=tsc(L"to"),.lang_term=tsc(L"ton"),.lang_lib=tsc(L"ton")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"to_TO"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Tongan language locale for Tonga"),.source=tsc(u8"International Components for Unicode\t\t;\t\tufio"),.address=tsc(u8"Samsung R & D Institute India - Delhi 2-A Sectort 126 Noida 201303\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Tongan"),.territory=tsc(u8"Tonga"),.revision=tsc(u8"1.0"),.date=tsc(u8"2017-03-23")},.monetary={.int_curr_symbol=tsc(u8"TOP "),.currency_symbol=tsc(u8"T$"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"Sāp"),tsc(u8"Mōn"),tsc(u8"Tūs"),tsc(u8"Pul"),tsc(u8"Tuʻa"),tsc(u8"Fal"),tsc(u8"Tok")},.day={tsc(u8"Sāpate"),tsc(u8"Mōnite"),tsc(u8"Tūsite"),tsc(u8"Pulelulu"),tsc(u8"Tuʻapulelulu"),tsc(u8"Falaite"),tsc(u8"Tokonaki")},.abmon={tsc(u8"Sān"),tsc(u8"Fēp"),tsc(u8"Maʻa"),tsc(u8"ʻEpe"),tsc(u8"Mē"),tsc(u8"Sun"),tsc(u8"Siu"),tsc(u8"ʻAok"),tsc(u8"Sep"),tsc(u8"ʻOka"),tsc(u8"Nōv"),tsc(u8"Tīs")},.mon={tsc(u8"Sānuali"),tsc(u8"Fēpueli"),tsc(u8"Maʻasi"),tsc(u8"ʻEpeleli"),tsc(u8"Mē"),tsc(u8"Sune"),tsc(u8"Siulai"),tsc(u8"ʻAokosi"),tsc(u8"Sepitema"),tsc(u8"ʻOkatopa"),tsc(u8"Nōvema"),tsc(u8"Tīsema")},.d_t_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u8"%A %d %b %Y"),.t_fmt=tsc(u8"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p %Z"),.date_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u8"hengihengi"),tsc(u8"efiafi")}},.messages={.yesexpr=tsc(u8"^[+1yY]"),.noexpr=tsc(u8"^[-0nN]"),.yesstr=tsc(u8"ʻIo"),.nostr=tsc(u8"ʻIkai")},.paper={.width=210,.height=297},.telephone={.int_select=tsc(u8"00"),.int_prefix=tsc(u8"676")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f"),.name_miss=tsc(u8"Miss."),.name_mr=tsc(u8"Mr."),.name_mrs=tsc(u8"Mrs."),.name_ms=tsc(u8"Ms.")},.address={.postal_fmt=tsc(u8"%a%b%s%c"),.country_name=tsc(u8"Tonga"),.country_post=tsc(u8""),.country_ab2=tsc(u8"TO"),.country_ab3=tsc(u8"TON"),.country_num=776,.country_car=tsc(u8"TON"),.lang_name=tsc(u8"lea fakatonga"),.lang_ab=tsc(u8"to"),.lang_term=tsc(u8"ton"),.lang_lib=tsc(u8"ton")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"to_TO"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Tongan language locale for Tonga"),.source=tsc(u"International Components for Unicode\t\t;\t\tufio"),.address=tsc(u"Samsung R & D Institute India - Delhi 2-A Sectort 126 Noida 201303\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Tongan"),.territory=tsc(u"Tonga"),.revision=tsc(u"1.0"),.date=tsc(u"2017-03-23")},.monetary={.int_curr_symbol=tsc(u"TOP "),.currency_symbol=tsc(u"T$"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"Sāp"),tsc(u"Mōn"),tsc(u"Tūs"),tsc(u"Pul"),tsc(u"Tuʻa"),tsc(u"Fal"),tsc(u"Tok")},.day={tsc(u"Sāpate"),tsc(u"Mōnite"),tsc(u"Tūsite"),tsc(u"Pulelulu"),tsc(u"Tuʻapulelulu"),tsc(u"Falaite"),tsc(u"Tokonaki")},.abmon={tsc(u"Sān"),tsc(u"Fēp"),tsc(u"Maʻa"),tsc(u"ʻEpe"),tsc(u"Mē"),tsc(u"Sun"),tsc(u"Siu"),tsc(u"ʻAok"),tsc(u"Sep"),tsc(u"ʻOka"),tsc(u"Nōv"),tsc(u"Tīs")},.mon={tsc(u"Sānuali"),tsc(u"Fēpueli"),tsc(u"Maʻasi"),tsc(u"ʻEpeleli"),tsc(u"Mē"),tsc(u"Sune"),tsc(u"Siulai"),tsc(u"ʻAokosi"),tsc(u"Sepitema"),tsc(u"ʻOkatopa"),tsc(u"Nōvema"),tsc(u"Tīsema")},.d_t_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u"%A %d %b %Y"),.t_fmt=tsc(u"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u"%I:%M:%S %p %Z"),.date_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u"hengihengi"),tsc(u"efiafi")}},.messages={.yesexpr=tsc(u"^[+1yY]"),.noexpr=tsc(u"^[-0nN]"),.yesstr=tsc(u"ʻIo"),.nostr=tsc(u"ʻIkai")},.paper={.width=210,.height=297},.telephone={.int_select=tsc(u"00"),.int_prefix=tsc(u"676")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f"),.name_miss=tsc(u"Miss."),.name_mr=tsc(u"Mr."),.name_mrs=tsc(u"Mrs."),.name_ms=tsc(u"Ms.")},.address={.postal_fmt=tsc(u"%a%b%s%c"),.country_name=tsc(u"Tonga"),.country_post=tsc(u""),.country_ab2=tsc(u"TO"),.country_ab3=tsc(u"TON"),.country_num=776,.country_car=tsc(u"TON"),.lang_name=tsc(u"lea fakatonga"),.lang_ab=tsc(u"to"),.lang_term=tsc(u"ton"),.lang_lib=tsc(u"ton")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"to_TO"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Tongan language locale for Tonga"),.source=tsc(U"International Components for Unicode\t\t;\t\tufio"),.address=tsc(U"Samsung R & D Institute India - Delhi 2-A Sectort 126 Noida 201303\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"akhilesh.k@samsung.com;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Tongan"),.territory=tsc(U"Tonga"),.revision=tsc(U"1.0"),.date=tsc(U"2017-03-23")},.monetary={.int_curr_symbol=tsc(U"TOP "),.currency_symbol=tsc(U"T$"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"Sāp"),tsc(U"Mōn"),tsc(U"Tūs"),tsc(U"Pul"),tsc(U"Tuʻa"),tsc(U"Fal"),tsc(U"Tok")},.day={tsc(U"Sāpate"),tsc(U"Mōnite"),tsc(U"Tūsite"),tsc(U"Pulelulu"),tsc(U"Tuʻapulelulu"),tsc(U"Falaite"),tsc(U"Tokonaki")},.abmon={tsc(U"Sān"),tsc(U"Fēp"),tsc(U"Maʻa"),tsc(U"ʻEpe"),tsc(U"Mē"),tsc(U"Sun"),tsc(U"Siu"),tsc(U"ʻAok"),tsc(U"Sep"),tsc(U"ʻOka"),tsc(U"Nōv"),tsc(U"Tīs")},.mon={tsc(U"Sānuali"),tsc(U"Fēpueli"),tsc(U"Maʻasi"),tsc(U"ʻEpeleli"),tsc(U"Mē"),tsc(U"Sune"),tsc(U"Siulai"),tsc(U"ʻAokosi"),tsc(U"Sepitema"),tsc(U"ʻOkatopa"),tsc(U"Nōvema"),tsc(U"Tīsema")},.d_t_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(U"%A %d %b %Y"),.t_fmt=tsc(U"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(U"%I:%M:%S %p %Z"),.date_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(U"hengihengi"),tsc(U"efiafi")}},.messages={.yesexpr=tsc(U"^[+1yY]"),.noexpr=tsc(U"^[-0nN]"),.yesstr=tsc(U"ʻIo"),.nostr=tsc(U"ʻIkai")},.paper={.width=210,.height=297},.telephone={.int_select=tsc(U"00"),.int_prefix=tsc(U"676")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f"),.name_miss=tsc(U"Miss."),.name_mr=tsc(U"Mr."),.name_mrs=tsc(U"Mrs."),.name_ms=tsc(U"Ms.")},.address={.postal_fmt=tsc(U"%a%b%s%c"),.country_name=tsc(U"Tonga"),.country_post=tsc(U""),.country_ab2=tsc(U"TO"),.country_ab3=tsc(U"TON"),.country_num=776,.country_car=tsc(U"TON"),.lang_name=tsc(U"lea fakatonga"),.lang_ab=tsc(U"to"),.lang_term=tsc(U"ton"),.lang_lib=tsc(U"ton")},.measurement={.measurement=1}};


}
}

#include"../main.h"