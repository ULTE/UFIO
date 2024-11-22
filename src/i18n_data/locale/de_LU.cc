﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("de_LU"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("German locale for Luxemburg"),.source=tsc("RAP\t\t;\t\tufio"),.address=tsc("Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("German"),.territory=tsc("Luxembourg"),.revision=tsc("1.0"),.date=tsc("2000-06-29")},.monetary={.int_curr_symbol=tsc("EUR "),.currency_symbol=tsc("€"),.mon_decimal_point=tsc(","),.mon_thousands_sep=tsc("."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(","),.thousands_sep=tsc("."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("So"),tsc("Mo"),tsc("Di"),tsc("Mi"),tsc("Do"),tsc("Fr"),tsc("Sa")},.day={tsc("Sonntag"),tsc("Montag"),tsc("Dienstag"),tsc("Mittwoch"),tsc("Donnerstag"),tsc("Freitag"),tsc("Samstag")},.abmon={tsc("Jan"),tsc("Feb"),tsc("Mär"),tsc("Apr"),tsc("Mai"),tsc("Jun"),tsc("Jul"),tsc("Aug"),tsc("Sep"),tsc("Okt"),tsc("Nov"),tsc("Dez")},.mon={tsc("Januar"),tsc("Februar"),tsc("März"),tsc("April"),tsc("Mai"),tsc("Juni"),tsc("Juli"),tsc("August"),tsc("September"),tsc("Oktober"),tsc("November"),tsc("Dezember")},.d_t_fmt=tsc("%a %d %b %Y %T"),.d_fmt=tsc("%Y-%m-%d"),.t_fmt=tsc("%T"),.t_fmt_ampm=tsc(""),.date_fmt=tsc("%a %d %b %Y %T %Z"),.am_pm={tsc(""),tsc("")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc("^[+1jJyY]"),.noexpr=tsc("^[-0nN]"),.yesstr=tsc("ja"),.nostr=tsc("nein")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("00"),.int_prefix=tsc("352")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Luxemburg"),.country_ab2=tsc("LU"),.country_ab3=tsc("LUX"),.country_num=442,.country_car=tsc("L"),.lang_name=tsc("Deutsch"),.lang_ab=tsc("de"),.lang_term=tsc("deu"),.lang_lib=tsc("ger")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"de_LU"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"German locale for Luxemburg"),.source=tsc(L"RAP\t\t;\t\tufio"),.address=tsc(L"Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"German"),.territory=tsc(L"Luxembourg"),.revision=tsc(L"1.0"),.date=tsc(L"2000-06-29")},.monetary={.int_curr_symbol=tsc(L"EUR "),.currency_symbol=tsc(L"€"),.mon_decimal_point=tsc(L","),.mon_thousands_sep=tsc(L"."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(L","),.thousands_sep=tsc(L"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"So"),tsc(L"Mo"),tsc(L"Di"),tsc(L"Mi"),tsc(L"Do"),tsc(L"Fr"),tsc(L"Sa")},.day={tsc(L"Sonntag"),tsc(L"Montag"),tsc(L"Dienstag"),tsc(L"Mittwoch"),tsc(L"Donnerstag"),tsc(L"Freitag"),tsc(L"Samstag")},.abmon={tsc(L"Jan"),tsc(L"Feb"),tsc(L"Mär"),tsc(L"Apr"),tsc(L"Mai"),tsc(L"Jun"),tsc(L"Jul"),tsc(L"Aug"),tsc(L"Sep"),tsc(L"Okt"),tsc(L"Nov"),tsc(L"Dez")},.mon={tsc(L"Januar"),tsc(L"Februar"),tsc(L"März"),tsc(L"April"),tsc(L"Mai"),tsc(L"Juni"),tsc(L"Juli"),tsc(L"August"),tsc(L"September"),tsc(L"Oktober"),tsc(L"November"),tsc(L"Dezember")},.d_t_fmt=tsc(L"%a %d %b %Y %T"),.d_fmt=tsc(L"%Y-%m-%d"),.t_fmt=tsc(L"%T"),.t_fmt_ampm=tsc(L""),.date_fmt=tsc(L"%a %d %b %Y %T %Z"),.am_pm={tsc(L""),tsc(L"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(L"^[+1jJyY]"),.noexpr=tsc(L"^[-0nN]"),.yesstr=tsc(L"ja"),.nostr=tsc(L"nein")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"352")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Luxemburg"),.country_ab2=tsc(L"LU"),.country_ab3=tsc(L"LUX"),.country_num=442,.country_car=tsc(L"L"),.lang_name=tsc(L"Deutsch"),.lang_ab=tsc(L"de"),.lang_term=tsc(L"deu"),.lang_lib=tsc(L"ger")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"de_LU"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"German locale for Luxemburg"),.source=tsc(u8"RAP\t\t;\t\tufio"),.address=tsc(u8"Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"German"),.territory=tsc(u8"Luxembourg"),.revision=tsc(u8"1.0"),.date=tsc(u8"2000-06-29")},.monetary={.int_curr_symbol=tsc(u8"EUR "),.currency_symbol=tsc(u8"€"),.mon_decimal_point=tsc(u8","),.mon_thousands_sep=tsc(u8"."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(u8","),.thousands_sep=tsc(u8"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"So"),tsc(u8"Mo"),tsc(u8"Di"),tsc(u8"Mi"),tsc(u8"Do"),tsc(u8"Fr"),tsc(u8"Sa")},.day={tsc(u8"Sonntag"),tsc(u8"Montag"),tsc(u8"Dienstag"),tsc(u8"Mittwoch"),tsc(u8"Donnerstag"),tsc(u8"Freitag"),tsc(u8"Samstag")},.abmon={tsc(u8"Jan"),tsc(u8"Feb"),tsc(u8"Mär"),tsc(u8"Apr"),tsc(u8"Mai"),tsc(u8"Jun"),tsc(u8"Jul"),tsc(u8"Aug"),tsc(u8"Sep"),tsc(u8"Okt"),tsc(u8"Nov"),tsc(u8"Dez")},.mon={tsc(u8"Januar"),tsc(u8"Februar"),tsc(u8"März"),tsc(u8"April"),tsc(u8"Mai"),tsc(u8"Juni"),tsc(u8"Juli"),tsc(u8"August"),tsc(u8"September"),tsc(u8"Oktober"),tsc(u8"November"),tsc(u8"Dezember")},.d_t_fmt=tsc(u8"%a %d %b %Y %T"),.d_fmt=tsc(u8"%Y-%m-%d"),.t_fmt=tsc(u8"%T"),.t_fmt_ampm=tsc(u8""),.date_fmt=tsc(u8"%a %d %b %Y %T %Z"),.am_pm={tsc(u8""),tsc(u8"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u8"^[+1jJyY]"),.noexpr=tsc(u8"^[-0nN]"),.yesstr=tsc(u8"ja"),.nostr=tsc(u8"nein")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"352")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Luxemburg"),.country_ab2=tsc(u8"LU"),.country_ab3=tsc(u8"LUX"),.country_num=442,.country_car=tsc(u8"L"),.lang_name=tsc(u8"Deutsch"),.lang_ab=tsc(u8"de"),.lang_term=tsc(u8"deu"),.lang_lib=tsc(u8"ger")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"de_LU"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"German locale for Luxemburg"),.source=tsc(u"RAP\t\t;\t\tufio"),.address=tsc(u"Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"German"),.territory=tsc(u"Luxembourg"),.revision=tsc(u"1.0"),.date=tsc(u"2000-06-29")},.monetary={.int_curr_symbol=tsc(u"EUR "),.currency_symbol=tsc(u"€"),.mon_decimal_point=tsc(u","),.mon_thousands_sep=tsc(u"."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(u","),.thousands_sep=tsc(u"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"So"),tsc(u"Mo"),tsc(u"Di"),tsc(u"Mi"),tsc(u"Do"),tsc(u"Fr"),tsc(u"Sa")},.day={tsc(u"Sonntag"),tsc(u"Montag"),tsc(u"Dienstag"),tsc(u"Mittwoch"),tsc(u"Donnerstag"),tsc(u"Freitag"),tsc(u"Samstag")},.abmon={tsc(u"Jan"),tsc(u"Feb"),tsc(u"Mär"),tsc(u"Apr"),tsc(u"Mai"),tsc(u"Jun"),tsc(u"Jul"),tsc(u"Aug"),tsc(u"Sep"),tsc(u"Okt"),tsc(u"Nov"),tsc(u"Dez")},.mon={tsc(u"Januar"),tsc(u"Februar"),tsc(u"März"),tsc(u"April"),tsc(u"Mai"),tsc(u"Juni"),tsc(u"Juli"),tsc(u"August"),tsc(u"September"),tsc(u"Oktober"),tsc(u"November"),tsc(u"Dezember")},.d_t_fmt=tsc(u"%a %d %b %Y %T"),.d_fmt=tsc(u"%Y-%m-%d"),.t_fmt=tsc(u"%T"),.t_fmt_ampm=tsc(u""),.date_fmt=tsc(u"%a %d %b %Y %T %Z"),.am_pm={tsc(u""),tsc(u"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u"^[+1jJyY]"),.noexpr=tsc(u"^[-0nN]"),.yesstr=tsc(u"ja"),.nostr=tsc(u"nein")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"352")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Luxemburg"),.country_ab2=tsc(u"LU"),.country_ab3=tsc(u"LUX"),.country_num=442,.country_car=tsc(u"L"),.lang_name=tsc(u"Deutsch"),.lang_ab=tsc(u"de"),.lang_term=tsc(u"deu"),.lang_lib=tsc(u"ger")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"de_LU"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"German locale for Luxemburg"),.source=tsc(U"RAP\t\t;\t\tufio"),.address=tsc(U"Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"German"),.territory=tsc(U"Luxembourg"),.revision=tsc(U"1.0"),.date=tsc(U"2000-06-29")},.monetary={.int_curr_symbol=tsc(U"EUR "),.currency_symbol=tsc(U"€"),.mon_decimal_point=tsc(U","),.mon_thousands_sep=tsc(U"."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(U","),.thousands_sep=tsc(U"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"So"),tsc(U"Mo"),tsc(U"Di"),tsc(U"Mi"),tsc(U"Do"),tsc(U"Fr"),tsc(U"Sa")},.day={tsc(U"Sonntag"),tsc(U"Montag"),tsc(U"Dienstag"),tsc(U"Mittwoch"),tsc(U"Donnerstag"),tsc(U"Freitag"),tsc(U"Samstag")},.abmon={tsc(U"Jan"),tsc(U"Feb"),tsc(U"Mär"),tsc(U"Apr"),tsc(U"Mai"),tsc(U"Jun"),tsc(U"Jul"),tsc(U"Aug"),tsc(U"Sep"),tsc(U"Okt"),tsc(U"Nov"),tsc(U"Dez")},.mon={tsc(U"Januar"),tsc(U"Februar"),tsc(U"März"),tsc(U"April"),tsc(U"Mai"),tsc(U"Juni"),tsc(U"Juli"),tsc(U"August"),tsc(U"September"),tsc(U"Oktober"),tsc(U"November"),tsc(U"Dezember")},.d_t_fmt=tsc(U"%a %d %b %Y %T"),.d_fmt=tsc(U"%Y-%m-%d"),.t_fmt=tsc(U"%T"),.t_fmt_ampm=tsc(U""),.date_fmt=tsc(U"%a %d %b %Y %T %Z"),.am_pm={tsc(U""),tsc(U"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(U"^[+1jJyY]"),.noexpr=tsc(U"^[-0nN]"),.yesstr=tsc(U"ja"),.nostr=tsc(U"nein")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"352")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Luxemburg"),.country_ab2=tsc(U"LU"),.country_ab3=tsc(U"LUX"),.country_num=442,.country_car=tsc(U"L"),.lang_name=tsc(U"Deutsch"),.lang_ab=tsc(U"de"),.lang_term=tsc(U"deu"),.lang_lib=tsc(U"ger")},.measurement={.measurement=1}};


}
}

#include"../main.h"