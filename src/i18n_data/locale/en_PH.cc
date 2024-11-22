﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("en_PH"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("English language locale for Philippines"),.source=tsc("IBM Globalization Center of Competency, Yamato Software Laboratory\t\t;\t\tufio"),.address=tsc("1623-14, Shimotsuruma, Yamato-shi, Kanagawa-ken, 242-8502, Japan\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("English"),.territory=tsc("Philippines"),.revision=tsc("1.0"),.date=tsc("2000,October,27 (XML source:2000,July,20)")},.monetary={.int_curr_symbol=tsc("PHP "),.currency_symbol=tsc("₱"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=0},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("Sun"),tsc("Mon"),tsc("Tue"),tsc("Wed"),tsc("Thu"),tsc("Fri"),tsc("Sat")},.day={tsc("Sunday"),tsc("Monday"),tsc("Tuesday"),tsc("Wednesday"),tsc("Thursday"),tsc("Friday"),tsc("Saturday")},.abmon={tsc("Jan"),tsc("Feb"),tsc("Mar"),tsc("Apr"),tsc("May"),tsc("Jun"),tsc("Jul"),tsc("Aug"),tsc("Sep"),tsc("Oct"),tsc("Nov"),tsc("Dec")},.mon={tsc("January"),tsc("February"),tsc("March"),tsc("April"),tsc("May"),tsc("June"),tsc("July"),tsc("August"),tsc("September"),tsc("October"),tsc("November"),tsc("December")},.d_t_fmt=tsc("%A, %d %B, %Y %I:%M:%S %p"),.d_fmt=tsc("%A, %d %B, %Y"),.t_fmt=tsc("%I:%M:%S %p %Z"),.t_fmt_ampm=tsc("%I:%M:%S %p %Z"),.date_fmt=tsc("%A, %d %B, %Y %I:%M:%S %p %Z"),.am_pm={tsc("AM"),tsc("PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc("^[+1yY]"),.noexpr=tsc("^[-0nN]"),.yesstr=tsc("yes"),.nostr=tsc("no")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc("+%c ;%a ;%l"),.int_select=tsc("00"),.int_prefix=tsc("63")},.name={.name_fmt=tsc("%p%t%f%t%g"),.name_gen=tsc(""),.name_miss=tsc("Miss."),.name_mr=tsc("Mr."),.name_mrs=tsc("Mrs."),.name_ms=tsc("Ms.")},.address={.postal_fmt=tsc("%z%c%T%s%b%e%r"),.country_name=tsc("Philippines"),.country_ab2=tsc("PH"),.country_ab3=tsc("PHL"),.country_num=608,.country_car=tsc("RP"),.lang_name=tsc("English"),.lang_ab=tsc("en"),.lang_term=tsc("eng"),.lang_lib=tsc("eng")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"en_PH"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"English language locale for Philippines"),.source=tsc(L"IBM Globalization Center of Competency, Yamato Software Laboratory\t\t;\t\tufio"),.address=tsc(L"1623-14, Shimotsuruma, Yamato-shi, Kanagawa-ken, 242-8502, Japan\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"English"),.territory=tsc(L"Philippines"),.revision=tsc(L"1.0"),.date=tsc(L"2000,October,27 (XML source:2000,July,20)")},.monetary={.int_curr_symbol=tsc(L"PHP "),.currency_symbol=tsc(L"₱"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=0},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"Sun"),tsc(L"Mon"),tsc(L"Tue"),tsc(L"Wed"),tsc(L"Thu"),tsc(L"Fri"),tsc(L"Sat")},.day={tsc(L"Sunday"),tsc(L"Monday"),tsc(L"Tuesday"),tsc(L"Wednesday"),tsc(L"Thursday"),tsc(L"Friday"),tsc(L"Saturday")},.abmon={tsc(L"Jan"),tsc(L"Feb"),tsc(L"Mar"),tsc(L"Apr"),tsc(L"May"),tsc(L"Jun"),tsc(L"Jul"),tsc(L"Aug"),tsc(L"Sep"),tsc(L"Oct"),tsc(L"Nov"),tsc(L"Dec")},.mon={tsc(L"January"),tsc(L"February"),tsc(L"March"),tsc(L"April"),tsc(L"May"),tsc(L"June"),tsc(L"July"),tsc(L"August"),tsc(L"September"),tsc(L"October"),tsc(L"November"),tsc(L"December")},.d_t_fmt=tsc(L"%A, %d %B, %Y %I:%M:%S %p"),.d_fmt=tsc(L"%A, %d %B, %Y"),.t_fmt=tsc(L"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(L"%I:%M:%S %p %Z"),.date_fmt=tsc(L"%A, %d %B, %Y %I:%M:%S %p %Z"),.am_pm={tsc(L"AM"),tsc(L"PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc(L"^[+1yY]"),.noexpr=tsc(L"^[-0nN]"),.yesstr=tsc(L"yes"),.nostr=tsc(L"no")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc(L"+%c ;%a ;%l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"63")},.name={.name_fmt=tsc(L"%p%t%f%t%g"),.name_gen=tsc(L""),.name_miss=tsc(L"Miss."),.name_mr=tsc(L"Mr."),.name_mrs=tsc(L"Mrs."),.name_ms=tsc(L"Ms.")},.address={.postal_fmt=tsc(L"%z%c%T%s%b%e%r"),.country_name=tsc(L"Philippines"),.country_ab2=tsc(L"PH"),.country_ab3=tsc(L"PHL"),.country_num=608,.country_car=tsc(L"RP"),.lang_name=tsc(L"English"),.lang_ab=tsc(L"en"),.lang_term=tsc(L"eng"),.lang_lib=tsc(L"eng")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"en_PH"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"English language locale for Philippines"),.source=tsc(u8"IBM Globalization Center of Competency, Yamato Software Laboratory\t\t;\t\tufio"),.address=tsc(u8"1623-14, Shimotsuruma, Yamato-shi, Kanagawa-ken, 242-8502, Japan\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"English"),.territory=tsc(u8"Philippines"),.revision=tsc(u8"1.0"),.date=tsc(u8"2000,October,27 (XML source:2000,July,20)")},.monetary={.int_curr_symbol=tsc(u8"PHP "),.currency_symbol=tsc(u8"₱"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=0},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"Sun"),tsc(u8"Mon"),tsc(u8"Tue"),tsc(u8"Wed"),tsc(u8"Thu"),tsc(u8"Fri"),tsc(u8"Sat")},.day={tsc(u8"Sunday"),tsc(u8"Monday"),tsc(u8"Tuesday"),tsc(u8"Wednesday"),tsc(u8"Thursday"),tsc(u8"Friday"),tsc(u8"Saturday")},.abmon={tsc(u8"Jan"),tsc(u8"Feb"),tsc(u8"Mar"),tsc(u8"Apr"),tsc(u8"May"),tsc(u8"Jun"),tsc(u8"Jul"),tsc(u8"Aug"),tsc(u8"Sep"),tsc(u8"Oct"),tsc(u8"Nov"),tsc(u8"Dec")},.mon={tsc(u8"January"),tsc(u8"February"),tsc(u8"March"),tsc(u8"April"),tsc(u8"May"),tsc(u8"June"),tsc(u8"July"),tsc(u8"August"),tsc(u8"September"),tsc(u8"October"),tsc(u8"November"),tsc(u8"December")},.d_t_fmt=tsc(u8"%A, %d %B, %Y %I:%M:%S %p"),.d_fmt=tsc(u8"%A, %d %B, %Y"),.t_fmt=tsc(u8"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p %Z"),.date_fmt=tsc(u8"%A, %d %B, %Y %I:%M:%S %p %Z"),.am_pm={tsc(u8"AM"),tsc(u8"PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u8"^[+1yY]"),.noexpr=tsc(u8"^[-0nN]"),.yesstr=tsc(u8"yes"),.nostr=tsc(u8"no")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc(u8"+%c ;%a ;%l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"63")},.name={.name_fmt=tsc(u8"%p%t%f%t%g"),.name_gen=tsc(u8""),.name_miss=tsc(u8"Miss."),.name_mr=tsc(u8"Mr."),.name_mrs=tsc(u8"Mrs."),.name_ms=tsc(u8"Ms.")},.address={.postal_fmt=tsc(u8"%z%c%T%s%b%e%r"),.country_name=tsc(u8"Philippines"),.country_ab2=tsc(u8"PH"),.country_ab3=tsc(u8"PHL"),.country_num=608,.country_car=tsc(u8"RP"),.lang_name=tsc(u8"English"),.lang_ab=tsc(u8"en"),.lang_term=tsc(u8"eng"),.lang_lib=tsc(u8"eng")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"en_PH"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"English language locale for Philippines"),.source=tsc(u"IBM Globalization Center of Competency, Yamato Software Laboratory\t\t;\t\tufio"),.address=tsc(u"1623-14, Shimotsuruma, Yamato-shi, Kanagawa-ken, 242-8502, Japan\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"English"),.territory=tsc(u"Philippines"),.revision=tsc(u"1.0"),.date=tsc(u"2000,October,27 (XML source:2000,July,20)")},.monetary={.int_curr_symbol=tsc(u"PHP "),.currency_symbol=tsc(u"₱"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=0},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"Sun"),tsc(u"Mon"),tsc(u"Tue"),tsc(u"Wed"),tsc(u"Thu"),tsc(u"Fri"),tsc(u"Sat")},.day={tsc(u"Sunday"),tsc(u"Monday"),tsc(u"Tuesday"),tsc(u"Wednesday"),tsc(u"Thursday"),tsc(u"Friday"),tsc(u"Saturday")},.abmon={tsc(u"Jan"),tsc(u"Feb"),tsc(u"Mar"),tsc(u"Apr"),tsc(u"May"),tsc(u"Jun"),tsc(u"Jul"),tsc(u"Aug"),tsc(u"Sep"),tsc(u"Oct"),tsc(u"Nov"),tsc(u"Dec")},.mon={tsc(u"January"),tsc(u"February"),tsc(u"March"),tsc(u"April"),tsc(u"May"),tsc(u"June"),tsc(u"July"),tsc(u"August"),tsc(u"September"),tsc(u"October"),tsc(u"November"),tsc(u"December")},.d_t_fmt=tsc(u"%A, %d %B, %Y %I:%M:%S %p"),.d_fmt=tsc(u"%A, %d %B, %Y"),.t_fmt=tsc(u"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u"%I:%M:%S %p %Z"),.date_fmt=tsc(u"%A, %d %B, %Y %I:%M:%S %p %Z"),.am_pm={tsc(u"AM"),tsc(u"PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u"^[+1yY]"),.noexpr=tsc(u"^[-0nN]"),.yesstr=tsc(u"yes"),.nostr=tsc(u"no")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc(u"+%c ;%a ;%l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"63")},.name={.name_fmt=tsc(u"%p%t%f%t%g"),.name_gen=tsc(u""),.name_miss=tsc(u"Miss."),.name_mr=tsc(u"Mr."),.name_mrs=tsc(u"Mrs."),.name_ms=tsc(u"Ms.")},.address={.postal_fmt=tsc(u"%z%c%T%s%b%e%r"),.country_name=tsc(u"Philippines"),.country_ab2=tsc(u"PH"),.country_ab3=tsc(u"PHL"),.country_num=608,.country_car=tsc(u"RP"),.lang_name=tsc(u"English"),.lang_ab=tsc(u"en"),.lang_term=tsc(u"eng"),.lang_lib=tsc(u"eng")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"en_PH"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"English language locale for Philippines"),.source=tsc(U"IBM Globalization Center of Competency, Yamato Software Laboratory\t\t;\t\tufio"),.address=tsc(U"1623-14, Shimotsuruma, Yamato-shi, Kanagawa-ken, 242-8502, Japan\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"English"),.territory=tsc(U"Philippines"),.revision=tsc(U"1.0"),.date=tsc(U"2000,October,27 (XML source:2000,July,20)")},.monetary={.int_curr_symbol=tsc(U"PHP "),.currency_symbol=tsc(U"₱"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=0},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"Sun"),tsc(U"Mon"),tsc(U"Tue"),tsc(U"Wed"),tsc(U"Thu"),tsc(U"Fri"),tsc(U"Sat")},.day={tsc(U"Sunday"),tsc(U"Monday"),tsc(U"Tuesday"),tsc(U"Wednesday"),tsc(U"Thursday"),tsc(U"Friday"),tsc(U"Saturday")},.abmon={tsc(U"Jan"),tsc(U"Feb"),tsc(U"Mar"),tsc(U"Apr"),tsc(U"May"),tsc(U"Jun"),tsc(U"Jul"),tsc(U"Aug"),tsc(U"Sep"),tsc(U"Oct"),tsc(U"Nov"),tsc(U"Dec")},.mon={tsc(U"January"),tsc(U"February"),tsc(U"March"),tsc(U"April"),tsc(U"May"),tsc(U"June"),tsc(U"July"),tsc(U"August"),tsc(U"September"),tsc(U"October"),tsc(U"November"),tsc(U"December")},.d_t_fmt=tsc(U"%A, %d %B, %Y %I:%M:%S %p"),.d_fmt=tsc(U"%A, %d %B, %Y"),.t_fmt=tsc(U"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(U"%I:%M:%S %p %Z"),.date_fmt=tsc(U"%A, %d %B, %Y %I:%M:%S %p %Z"),.am_pm={tsc(U"AM"),tsc(U"PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc(U"^[+1yY]"),.noexpr=tsc(U"^[-0nN]"),.yesstr=tsc(U"yes"),.nostr=tsc(U"no")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc(U"+%c ;%a ;%l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"63")},.name={.name_fmt=tsc(U"%p%t%f%t%g"),.name_gen=tsc(U""),.name_miss=tsc(U"Miss."),.name_mr=tsc(U"Mr."),.name_mrs=tsc(U"Mrs."),.name_ms=tsc(U"Ms.")},.address={.postal_fmt=tsc(U"%z%c%T%s%b%e%r"),.country_name=tsc(U"Philippines"),.country_ab2=tsc(U"PH"),.country_ab3=tsc(U"PHL"),.country_num=608,.country_car=tsc(U"RP"),.lang_name=tsc(U"English"),.lang_ab=tsc(U"en"),.lang_term=tsc(U"eng"),.lang_lib=tsc(U"eng")},.measurement={.measurement=1}};


}
}

#include"../main.h"