﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("fr_CH"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("French locale for Switzerland"),.source=tsc("RAP\t\t;\t\tufio"),.address=tsc("Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Swiss French"),.territory=tsc("Switzerland"),.revision=tsc("1.0"),.date=tsc("2000-06-29")},.monetary={.int_curr_symbol=tsc("CHF "),.currency_symbol=tsc("CHF"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc("’"),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc("’"),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("dim"),tsc("lun"),tsc("mar"),tsc("mer"),tsc("jeu"),tsc("ven"),tsc("sam")},.day={tsc("dimanche"),tsc("lundi"),tsc("mardi"),tsc("mercredi"),tsc("jeudi"),tsc("vendredi"),tsc("samedi")},.abmon={tsc("jan"),tsc("fév"),tsc("mar"),tsc("avr"),tsc("mai"),tsc("jun"),tsc("jui"),tsc("aoû"),tsc("sep"),tsc("oct"),tsc("nov"),tsc("déc")},.mon={tsc("janvier"),tsc("février"),tsc("mars"),tsc("avril"),tsc("mai"),tsc("juin"),tsc("juillet"),tsc("août"),tsc("septembre"),tsc("octobre"),tsc("novembre"),tsc("décembre")},.d_t_fmt=tsc("%a %d %b %Y %T"),.d_fmt=tsc("%d. %m. %y"),.t_fmt=tsc("%T"),.t_fmt_ampm=tsc(""),.date_fmt=tsc("%a %d %b %Y %T %Z"),.am_pm={tsc(""),tsc("")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc("^[+1OojJsSyY]"),.noexpr=tsc("^[-0nN]"),.yesstr=tsc("oui"),.nostr=tsc("non")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("00"),.int_prefix=tsc("41")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Suisse"),.country_ab2=tsc("CH"),.country_ab3=tsc("CHE"),.country_num=756,.country_car=tsc("CH"),.lang_name=tsc("français"),.lang_ab=tsc("fr"),.lang_term=tsc("fra"),.lang_lib=tsc("fre")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"fr_CH"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"French locale for Switzerland"),.source=tsc(L"RAP\t\t;\t\tufio"),.address=tsc(L"Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Swiss French"),.territory=tsc(L"Switzerland"),.revision=tsc(L"1.0"),.date=tsc(L"2000-06-29")},.monetary={.int_curr_symbol=tsc(L"CHF "),.currency_symbol=tsc(L"CHF"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L"’"),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L"’"),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"dim"),tsc(L"lun"),tsc(L"mar"),tsc(L"mer"),tsc(L"jeu"),tsc(L"ven"),tsc(L"sam")},.day={tsc(L"dimanche"),tsc(L"lundi"),tsc(L"mardi"),tsc(L"mercredi"),tsc(L"jeudi"),tsc(L"vendredi"),tsc(L"samedi")},.abmon={tsc(L"jan"),tsc(L"fév"),tsc(L"mar"),tsc(L"avr"),tsc(L"mai"),tsc(L"jun"),tsc(L"jui"),tsc(L"aoû"),tsc(L"sep"),tsc(L"oct"),tsc(L"nov"),tsc(L"déc")},.mon={tsc(L"janvier"),tsc(L"février"),tsc(L"mars"),tsc(L"avril"),tsc(L"mai"),tsc(L"juin"),tsc(L"juillet"),tsc(L"août"),tsc(L"septembre"),tsc(L"octobre"),tsc(L"novembre"),tsc(L"décembre")},.d_t_fmt=tsc(L"%a %d %b %Y %T"),.d_fmt=tsc(L"%d. %m. %y"),.t_fmt=tsc(L"%T"),.t_fmt_ampm=tsc(L""),.date_fmt=tsc(L"%a %d %b %Y %T %Z"),.am_pm={tsc(L""),tsc(L"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(L"^[+1OojJsSyY]"),.noexpr=tsc(L"^[-0nN]"),.yesstr=tsc(L"oui"),.nostr=tsc(L"non")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"41")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Suisse"),.country_ab2=tsc(L"CH"),.country_ab3=tsc(L"CHE"),.country_num=756,.country_car=tsc(L"CH"),.lang_name=tsc(L"français"),.lang_ab=tsc(L"fr"),.lang_term=tsc(L"fra"),.lang_lib=tsc(L"fre")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"fr_CH"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"French locale for Switzerland"),.source=tsc(u8"RAP\t\t;\t\tufio"),.address=tsc(u8"Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Swiss French"),.territory=tsc(u8"Switzerland"),.revision=tsc(u8"1.0"),.date=tsc(u8"2000-06-29")},.monetary={.int_curr_symbol=tsc(u8"CHF "),.currency_symbol=tsc(u8"CHF"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8"’"),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8"’"),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"dim"),tsc(u8"lun"),tsc(u8"mar"),tsc(u8"mer"),tsc(u8"jeu"),tsc(u8"ven"),tsc(u8"sam")},.day={tsc(u8"dimanche"),tsc(u8"lundi"),tsc(u8"mardi"),tsc(u8"mercredi"),tsc(u8"jeudi"),tsc(u8"vendredi"),tsc(u8"samedi")},.abmon={tsc(u8"jan"),tsc(u8"fév"),tsc(u8"mar"),tsc(u8"avr"),tsc(u8"mai"),tsc(u8"jun"),tsc(u8"jui"),tsc(u8"aoû"),tsc(u8"sep"),tsc(u8"oct"),tsc(u8"nov"),tsc(u8"déc")},.mon={tsc(u8"janvier"),tsc(u8"février"),tsc(u8"mars"),tsc(u8"avril"),tsc(u8"mai"),tsc(u8"juin"),tsc(u8"juillet"),tsc(u8"août"),tsc(u8"septembre"),tsc(u8"octobre"),tsc(u8"novembre"),tsc(u8"décembre")},.d_t_fmt=tsc(u8"%a %d %b %Y %T"),.d_fmt=tsc(u8"%d. %m. %y"),.t_fmt=tsc(u8"%T"),.t_fmt_ampm=tsc(u8""),.date_fmt=tsc(u8"%a %d %b %Y %T %Z"),.am_pm={tsc(u8""),tsc(u8"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u8"^[+1OojJsSyY]"),.noexpr=tsc(u8"^[-0nN]"),.yesstr=tsc(u8"oui"),.nostr=tsc(u8"non")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"41")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Suisse"),.country_ab2=tsc(u8"CH"),.country_ab3=tsc(u8"CHE"),.country_num=756,.country_car=tsc(u8"CH"),.lang_name=tsc(u8"français"),.lang_ab=tsc(u8"fr"),.lang_term=tsc(u8"fra"),.lang_lib=tsc(u8"fre")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"fr_CH"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"French locale for Switzerland"),.source=tsc(u"RAP\t\t;\t\tufio"),.address=tsc(u"Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Swiss French"),.territory=tsc(u"Switzerland"),.revision=tsc(u"1.0"),.date=tsc(u"2000-06-29")},.monetary={.int_curr_symbol=tsc(u"CHF "),.currency_symbol=tsc(u"CHF"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u"’"),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u"’"),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"dim"),tsc(u"lun"),tsc(u"mar"),tsc(u"mer"),tsc(u"jeu"),tsc(u"ven"),tsc(u"sam")},.day={tsc(u"dimanche"),tsc(u"lundi"),tsc(u"mardi"),tsc(u"mercredi"),tsc(u"jeudi"),tsc(u"vendredi"),tsc(u"samedi")},.abmon={tsc(u"jan"),tsc(u"fév"),tsc(u"mar"),tsc(u"avr"),tsc(u"mai"),tsc(u"jun"),tsc(u"jui"),tsc(u"aoû"),tsc(u"sep"),tsc(u"oct"),tsc(u"nov"),tsc(u"déc")},.mon={tsc(u"janvier"),tsc(u"février"),tsc(u"mars"),tsc(u"avril"),tsc(u"mai"),tsc(u"juin"),tsc(u"juillet"),tsc(u"août"),tsc(u"septembre"),tsc(u"octobre"),tsc(u"novembre"),tsc(u"décembre")},.d_t_fmt=tsc(u"%a %d %b %Y %T"),.d_fmt=tsc(u"%d. %m. %y"),.t_fmt=tsc(u"%T"),.t_fmt_ampm=tsc(u""),.date_fmt=tsc(u"%a %d %b %Y %T %Z"),.am_pm={tsc(u""),tsc(u"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u"^[+1OojJsSyY]"),.noexpr=tsc(u"^[-0nN]"),.yesstr=tsc(u"oui"),.nostr=tsc(u"non")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"41")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Suisse"),.country_ab2=tsc(u"CH"),.country_ab3=tsc(u"CHE"),.country_num=756,.country_car=tsc(u"CH"),.lang_name=tsc(u"français"),.lang_ab=tsc(u"fr"),.lang_term=tsc(u"fra"),.lang_lib=tsc(u"fre")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"fr_CH"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"French locale for Switzerland"),.source=tsc(U"RAP\t\t;\t\tufio"),.address=tsc(U"Sankt Jørgens Alle 8, DK-1615 København V, Danmark\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Swiss French"),.territory=tsc(U"Switzerland"),.revision=tsc(U"1.0"),.date=tsc(U"2000-06-29")},.monetary={.int_curr_symbol=tsc(U"CHF "),.currency_symbol=tsc(U"CHF"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U"’"),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U"’"),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"dim"),tsc(U"lun"),tsc(U"mar"),tsc(U"mer"),tsc(U"jeu"),tsc(U"ven"),tsc(U"sam")},.day={tsc(U"dimanche"),tsc(U"lundi"),tsc(U"mardi"),tsc(U"mercredi"),tsc(U"jeudi"),tsc(U"vendredi"),tsc(U"samedi")},.abmon={tsc(U"jan"),tsc(U"fév"),tsc(U"mar"),tsc(U"avr"),tsc(U"mai"),tsc(U"jun"),tsc(U"jui"),tsc(U"aoû"),tsc(U"sep"),tsc(U"oct"),tsc(U"nov"),tsc(U"déc")},.mon={tsc(U"janvier"),tsc(U"février"),tsc(U"mars"),tsc(U"avril"),tsc(U"mai"),tsc(U"juin"),tsc(U"juillet"),tsc(U"août"),tsc(U"septembre"),tsc(U"octobre"),tsc(U"novembre"),tsc(U"décembre")},.d_t_fmt=tsc(U"%a %d %b %Y %T"),.d_fmt=tsc(U"%d. %m. %y"),.t_fmt=tsc(U"%T"),.t_fmt_ampm=tsc(U""),.date_fmt=tsc(U"%a %d %b %Y %T %Z"),.am_pm={tsc(U""),tsc(U"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(U"^[+1OojJsSyY]"),.noexpr=tsc(U"^[-0nN]"),.yesstr=tsc(U"oui"),.nostr=tsc(U"non")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"41")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Suisse"),.country_ab2=tsc(U"CH"),.country_ab3=tsc(U"CHE"),.country_num=756,.country_car=tsc(U"CH"),.lang_name=tsc(U"français"),.lang_ab=tsc(U"fr"),.lang_term=tsc(U"fra"),.lang_lib=tsc(U"fre")},.measurement={.measurement=1}};


}
}

#include"../main.h"