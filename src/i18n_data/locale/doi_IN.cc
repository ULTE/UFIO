﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t monetary_mon_grouping_storage[]{3,2};

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("doi_IN"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Dogri language locale for India"),.source=tsc("Red Hat Pune\t\t;\t\tufio"),.address=tsc("Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Dogri"),.territory=tsc("India"),.revision=tsc("1.0"),.date=tsc("2012-02-16")},.monetary={.int_curr_symbol=tsc("INR "),.currency_symbol=tsc("₹"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("ऐत"),tsc("सोम"),tsc("मंगल"),tsc("बुध"),tsc("बीर"),tsc("शुक्कर"),tsc("श्नीचर")},.day={tsc("ऐतबार"),tsc("सोमबार"),tsc("मंगलबर"),tsc("बुधबार"),tsc("बीरबार"),tsc("शुक्करबार"),tsc("श्नीचरबार")},.abmon={tsc("जनवरी"),tsc("फरवरी"),tsc("मार्च"),tsc("एप्रैल"),tsc("मेई"),tsc("जून"),tsc("जूलै"),tsc("अगस्त"),tsc("सितंबर"),tsc("अक्तूबर"),tsc("नवंबर"),tsc("दिसंबर")},.mon={tsc("जनवरी"),tsc("फरवरी"),tsc("मार्च"),tsc("एप्रैल"),tsc("मेई"),tsc("जून"),tsc("जूलै"),tsc("अगस्त"),tsc("सितंबर"),tsc("अक्तूबर"),tsc("नवंबर"),tsc("दिसंबर")},.d_t_fmt=tsc("%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc("%-d//%-m//%y"),.t_fmt=tsc("%I:%M:%S %p %Z"),.t_fmt_ampm=tsc("%I:%M:%S %p %Z"),.date_fmt=tsc("%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc("सञं"),tsc("सबेर")},.week={7,19971130,1}},.messages={.yesexpr=tsc("^[+1yYऑ]"),.noexpr=tsc("^[-0nNन]"),.yesstr=tsc("ऑह"),.nostr=tsc("ना")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c ;%a ;%l"),.int_select=tsc("00"),.int_prefix=tsc("91")},.name={.name_fmt=tsc("%p%t%f%t%g"),.name_gen=tsc(""),.name_miss=tsc("Miss."),.name_mr=tsc("Mr."),.name_mrs=tsc("Mrs."),.name_ms=tsc("Ms.")},.address={.postal_fmt=tsc("%z%c%T%s%b%e%r"),.country_name=tsc("भारत"),.country_ab2=tsc("IN"),.country_ab3=tsc("IND"),.country_num=356,.country_car=tsc("IND"),.lang_name=tsc("डोगरी"),.lang_term=tsc("doi"),.lang_lib=tsc("doi")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"doi_IN"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Dogri language locale for India"),.source=tsc(L"Red Hat Pune\t\t;\t\tufio"),.address=tsc(L"Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Dogri"),.territory=tsc(L"India"),.revision=tsc(L"1.0"),.date=tsc(L"2012-02-16")},.monetary={.int_curr_symbol=tsc(L"INR "),.currency_symbol=tsc(L"₹"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"ऐत"),tsc(L"सोम"),tsc(L"मंगल"),tsc(L"बुध"),tsc(L"बीर"),tsc(L"शुक्कर"),tsc(L"श्नीचर")},.day={tsc(L"ऐतबार"),tsc(L"सोमबार"),tsc(L"मंगलबर"),tsc(L"बुधबार"),tsc(L"बीरबार"),tsc(L"शुक्करबार"),tsc(L"श्नीचरबार")},.abmon={tsc(L"जनवरी"),tsc(L"फरवरी"),tsc(L"मार्च"),tsc(L"एप्रैल"),tsc(L"मेई"),tsc(L"जून"),tsc(L"जूलै"),tsc(L"अगस्त"),tsc(L"सितंबर"),tsc(L"अक्तूबर"),tsc(L"नवंबर"),tsc(L"दिसंबर")},.mon={tsc(L"जनवरी"),tsc(L"फरवरी"),tsc(L"मार्च"),tsc(L"एप्रैल"),tsc(L"मेई"),tsc(L"जून"),tsc(L"जूलै"),tsc(L"अगस्त"),tsc(L"सितंबर"),tsc(L"अक्तूबर"),tsc(L"नवंबर"),tsc(L"दिसंबर")},.d_t_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(L"%-d//%-m//%y"),.t_fmt=tsc(L"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(L"%I:%M:%S %p %Z"),.date_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(L"सञं"),tsc(L"सबेर")},.week={7,19971130,1}},.messages={.yesexpr=tsc(L"^[+1yYऑ]"),.noexpr=tsc(L"^[-0nNन]"),.yesstr=tsc(L"ऑह"),.nostr=tsc(L"ना")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c ;%a ;%l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"91")},.name={.name_fmt=tsc(L"%p%t%f%t%g"),.name_gen=tsc(L""),.name_miss=tsc(L"Miss."),.name_mr=tsc(L"Mr."),.name_mrs=tsc(L"Mrs."),.name_ms=tsc(L"Ms.")},.address={.postal_fmt=tsc(L"%z%c%T%s%b%e%r"),.country_name=tsc(L"भारत"),.country_ab2=tsc(L"IN"),.country_ab3=tsc(L"IND"),.country_num=356,.country_car=tsc(L"IND"),.lang_name=tsc(L"डोगरी"),.lang_term=tsc(L"doi"),.lang_lib=tsc(L"doi")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"doi_IN"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Dogri language locale for India"),.source=tsc(u8"Red Hat Pune\t\t;\t\tufio"),.address=tsc(u8"Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Dogri"),.territory=tsc(u8"India"),.revision=tsc(u8"1.0"),.date=tsc(u8"2012-02-16")},.monetary={.int_curr_symbol=tsc(u8"INR "),.currency_symbol=tsc(u8"₹"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"ऐत"),tsc(u8"सोम"),tsc(u8"मंगल"),tsc(u8"बुध"),tsc(u8"बीर"),tsc(u8"शुक्कर"),tsc(u8"श्नीचर")},.day={tsc(u8"ऐतबार"),tsc(u8"सोमबार"),tsc(u8"मंगलबर"),tsc(u8"बुधबार"),tsc(u8"बीरबार"),tsc(u8"शुक्करबार"),tsc(u8"श्नीचरबार")},.abmon={tsc(u8"जनवरी"),tsc(u8"फरवरी"),tsc(u8"मार्च"),tsc(u8"एप्रैल"),tsc(u8"मेई"),tsc(u8"जून"),tsc(u8"जूलै"),tsc(u8"अगस्त"),tsc(u8"सितंबर"),tsc(u8"अक्तूबर"),tsc(u8"नवंबर"),tsc(u8"दिसंबर")},.mon={tsc(u8"जनवरी"),tsc(u8"फरवरी"),tsc(u8"मार्च"),tsc(u8"एप्रैल"),tsc(u8"मेई"),tsc(u8"जून"),tsc(u8"जूलै"),tsc(u8"अगस्त"),tsc(u8"सितंबर"),tsc(u8"अक्तूबर"),tsc(u8"नवंबर"),tsc(u8"दिसंबर")},.d_t_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u8"%-d//%-m//%y"),.t_fmt=tsc(u8"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p %Z"),.date_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u8"सञं"),tsc(u8"सबेर")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u8"^[+1yYऑ]"),.noexpr=tsc(u8"^[-0nNन]"),.yesstr=tsc(u8"ऑह"),.nostr=tsc(u8"ना")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c ;%a ;%l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"91")},.name={.name_fmt=tsc(u8"%p%t%f%t%g"),.name_gen=tsc(u8""),.name_miss=tsc(u8"Miss."),.name_mr=tsc(u8"Mr."),.name_mrs=tsc(u8"Mrs."),.name_ms=tsc(u8"Ms.")},.address={.postal_fmt=tsc(u8"%z%c%T%s%b%e%r"),.country_name=tsc(u8"भारत"),.country_ab2=tsc(u8"IN"),.country_ab3=tsc(u8"IND"),.country_num=356,.country_car=tsc(u8"IND"),.lang_name=tsc(u8"डोगरी"),.lang_term=tsc(u8"doi"),.lang_lib=tsc(u8"doi")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"doi_IN"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Dogri language locale for India"),.source=tsc(u"Red Hat Pune\t\t;\t\tufio"),.address=tsc(u"Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Dogri"),.territory=tsc(u"India"),.revision=tsc(u"1.0"),.date=tsc(u"2012-02-16")},.monetary={.int_curr_symbol=tsc(u"INR "),.currency_symbol=tsc(u"₹"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"ऐत"),tsc(u"सोम"),tsc(u"मंगल"),tsc(u"बुध"),tsc(u"बीर"),tsc(u"शुक्कर"),tsc(u"श्नीचर")},.day={tsc(u"ऐतबार"),tsc(u"सोमबार"),tsc(u"मंगलबर"),tsc(u"बुधबार"),tsc(u"बीरबार"),tsc(u"शुक्करबार"),tsc(u"श्नीचरबार")},.abmon={tsc(u"जनवरी"),tsc(u"फरवरी"),tsc(u"मार्च"),tsc(u"एप्रैल"),tsc(u"मेई"),tsc(u"जून"),tsc(u"जूलै"),tsc(u"अगस्त"),tsc(u"सितंबर"),tsc(u"अक्तूबर"),tsc(u"नवंबर"),tsc(u"दिसंबर")},.mon={tsc(u"जनवरी"),tsc(u"फरवरी"),tsc(u"मार्च"),tsc(u"एप्रैल"),tsc(u"मेई"),tsc(u"जून"),tsc(u"जूलै"),tsc(u"अगस्त"),tsc(u"सितंबर"),tsc(u"अक्तूबर"),tsc(u"नवंबर"),tsc(u"दिसंबर")},.d_t_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u"%-d//%-m//%y"),.t_fmt=tsc(u"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u"%I:%M:%S %p %Z"),.date_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u"सञं"),tsc(u"सबेर")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u"^[+1yYऑ]"),.noexpr=tsc(u"^[-0nNन]"),.yesstr=tsc(u"ऑह"),.nostr=tsc(u"ना")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c ;%a ;%l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"91")},.name={.name_fmt=tsc(u"%p%t%f%t%g"),.name_gen=tsc(u""),.name_miss=tsc(u"Miss."),.name_mr=tsc(u"Mr."),.name_mrs=tsc(u"Mrs."),.name_ms=tsc(u"Ms.")},.address={.postal_fmt=tsc(u"%z%c%T%s%b%e%r"),.country_name=tsc(u"भारत"),.country_ab2=tsc(u"IN"),.country_ab3=tsc(u"IND"),.country_num=356,.country_car=tsc(u"IND"),.lang_name=tsc(u"डोगरी"),.lang_term=tsc(u"doi"),.lang_lib=tsc(u"doi")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"doi_IN"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Dogri language locale for India"),.source=tsc(U"Red Hat Pune\t\t;\t\tufio"),.address=tsc(U"Level 1, Tower X, Cybercity, Magarpatta City, Hadapsar, Pune-411013 \t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Dogri"),.territory=tsc(U"India"),.revision=tsc(U"1.0"),.date=tsc(U"2012-02-16")},.monetary={.int_curr_symbol=tsc(U"INR "),.currency_symbol=tsc(U"₹"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"ऐत"),tsc(U"सोम"),tsc(U"मंगल"),tsc(U"बुध"),tsc(U"बीर"),tsc(U"शुक्कर"),tsc(U"श्नीचर")},.day={tsc(U"ऐतबार"),tsc(U"सोमबार"),tsc(U"मंगलबर"),tsc(U"बुधबार"),tsc(U"बीरबार"),tsc(U"शुक्करबार"),tsc(U"श्नीचरबार")},.abmon={tsc(U"जनवरी"),tsc(U"फरवरी"),tsc(U"मार्च"),tsc(U"एप्रैल"),tsc(U"मेई"),tsc(U"जून"),tsc(U"जूलै"),tsc(U"अगस्त"),tsc(U"सितंबर"),tsc(U"अक्तूबर"),tsc(U"नवंबर"),tsc(U"दिसंबर")},.mon={tsc(U"जनवरी"),tsc(U"फरवरी"),tsc(U"मार्च"),tsc(U"एप्रैल"),tsc(U"मेई"),tsc(U"जून"),tsc(U"जूलै"),tsc(U"अगस्त"),tsc(U"सितंबर"),tsc(U"अक्तूबर"),tsc(U"नवंबर"),tsc(U"दिसंबर")},.d_t_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(U"%-d//%-m//%y"),.t_fmt=tsc(U"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(U"%I:%M:%S %p %Z"),.date_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(U"सञं"),tsc(U"सबेर")},.week={7,19971130,1}},.messages={.yesexpr=tsc(U"^[+1yYऑ]"),.noexpr=tsc(U"^[-0nNन]"),.yesstr=tsc(U"ऑह"),.nostr=tsc(U"ना")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c ;%a ;%l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"91")},.name={.name_fmt=tsc(U"%p%t%f%t%g"),.name_gen=tsc(U""),.name_miss=tsc(U"Miss."),.name_mr=tsc(U"Mr."),.name_mrs=tsc(U"Mrs."),.name_ms=tsc(U"Ms.")},.address={.postal_fmt=tsc(U"%z%c%T%s%b%e%r"),.country_name=tsc(U"भारत"),.country_ab2=tsc(U"IN"),.country_ab3=tsc(U"IND"),.country_num=356,.country_car=tsc(U"IND"),.lang_name=tsc(U"डोगरी"),.lang_term=tsc(U"doi"),.lang_lib=tsc(U"doi")},.measurement={.measurement=1}};


}
}

#include"../main.h"