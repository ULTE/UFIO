﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t monetary_mon_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("so_DJ"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Somali language locale for Djibouti."),.source=tsc("Ge'ez Frontier Foundation\t\t;\t\tufio"),.address=tsc("7802 Solomon Seal Dr., Springfield, VA 22152, USA\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("locales@geez.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Somali"),.territory=tsc("Djibouti"),.revision=tsc("0.20"),.date=tsc("2003-07-05")},.monetary={.int_curr_symbol=tsc("DJF "),.currency_symbol=tsc("Fdj"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(" "),.mon_grouping={monetary_mon_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc("")},.time={.abday={tsc("Axd"),tsc("Isn"),tsc("Tal"),tsc("Arb"),tsc("Kha"),tsc("Jim"),tsc("Sab")},.day={tsc("Axad"),tsc("Isniin"),tsc("Salaaso"),tsc("Arbaco"),tsc("Khamiis"),tsc("Jimco"),tsc("Sabti")},.abmon={tsc("Kob"),tsc("Lab"),tsc("Sad"),tsc("Afr"),tsc("Sha"),tsc("Lix"),tsc("Tod"),tsc("Sid"),tsc("Sag"),tsc("Tob"),tsc("KIT"),tsc("LIT")},.mon={tsc("Bisha Koobaad"),tsc("Bisha Labaad"),tsc("Bisha Saddexaad"),tsc("Bisha Afraad"),tsc("Bisha Shanaad"),tsc("Bisha Lixaad"),tsc("Bisha Todobaad"),tsc("Bisha Sideedaad"),tsc("Bisha Sagaalaad"),tsc("Bisha Tobnaad"),tsc("Bisha Kow iyo Tobnaad"),tsc("Bisha Laba iyo Tobnaad")},.d_t_fmt=tsc("%a %d %b %Y %r %Z"),.d_fmt=tsc("%d.%m.%Y"),.t_fmt=tsc("%l:%M:%S %p"),.t_fmt_ampm=tsc("%l:%M:%S %p"),.date_fmt=tsc("%a %b %e %r %Z %Y"),.am_pm={tsc("subaxnimo"),tsc("galabnimo")},.week={7,19971130,1},.first_weekday=7},.messages={.yesexpr=tsc("^[+1oOyY]"),.noexpr=tsc("^[-0nN]"),.yesstr=tsc("haa"),.nostr=tsc("maya")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.tel_dom_fmt=tsc("%a-%l"),.int_select=tsc("00"),.int_prefix=tsc("253")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f"),.name_gen=tsc(""),.name_miss=tsc(""),.name_mr=tsc("Md"),.name_mrs=tsc("Mw"),.name_ms=tsc("Mw")},.address={.postal_fmt=tsc("%z%c%T%s%b%e%r"),.country_name=tsc("Jabuuti"),.country_post=tsc("DJI"),.country_ab2=tsc("DJ"),.country_ab3=tsc("DJI"),.country_num=262,.country_car=tsc("DJI"),.lang_name=tsc("Soomaali"),.lang_ab=tsc("so"),.lang_term=tsc("som"),.lang_lib=tsc("som")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"so_DJ"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Somali language locale for Djibouti."),.source=tsc(L"Ge'ez Frontier Foundation\t\t;\t\tufio"),.address=tsc(L"7802 Solomon Seal Dr., Springfield, VA 22152, USA\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"locales@geez.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Somali"),.territory=tsc(L"Djibouti"),.revision=tsc(L"0.20"),.date=tsc(L"2003-07-05")},.monetary={.int_curr_symbol=tsc(L"DJF "),.currency_symbol=tsc(L"Fdj"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L" "),.mon_grouping={monetary_mon_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L"")},.time={.abday={tsc(L"Axd"),tsc(L"Isn"),tsc(L"Tal"),tsc(L"Arb"),tsc(L"Kha"),tsc(L"Jim"),tsc(L"Sab")},.day={tsc(L"Axad"),tsc(L"Isniin"),tsc(L"Salaaso"),tsc(L"Arbaco"),tsc(L"Khamiis"),tsc(L"Jimco"),tsc(L"Sabti")},.abmon={tsc(L"Kob"),tsc(L"Lab"),tsc(L"Sad"),tsc(L"Afr"),tsc(L"Sha"),tsc(L"Lix"),tsc(L"Tod"),tsc(L"Sid"),tsc(L"Sag"),tsc(L"Tob"),tsc(L"KIT"),tsc(L"LIT")},.mon={tsc(L"Bisha Koobaad"),tsc(L"Bisha Labaad"),tsc(L"Bisha Saddexaad"),tsc(L"Bisha Afraad"),tsc(L"Bisha Shanaad"),tsc(L"Bisha Lixaad"),tsc(L"Bisha Todobaad"),tsc(L"Bisha Sideedaad"),tsc(L"Bisha Sagaalaad"),tsc(L"Bisha Tobnaad"),tsc(L"Bisha Kow iyo Tobnaad"),tsc(L"Bisha Laba iyo Tobnaad")},.d_t_fmt=tsc(L"%a %d %b %Y %r %Z"),.d_fmt=tsc(L"%d.%m.%Y"),.t_fmt=tsc(L"%l:%M:%S %p"),.t_fmt_ampm=tsc(L"%l:%M:%S %p"),.date_fmt=tsc(L"%a %b %e %r %Z %Y"),.am_pm={tsc(L"subaxnimo"),tsc(L"galabnimo")},.week={7,19971130,1},.first_weekday=7},.messages={.yesexpr=tsc(L"^[+1oOyY]"),.noexpr=tsc(L"^[-0nN]"),.yesstr=tsc(L"haa"),.nostr=tsc(L"maya")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.tel_dom_fmt=tsc(L"%a-%l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"253")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f"),.name_gen=tsc(L""),.name_miss=tsc(L""),.name_mr=tsc(L"Md"),.name_mrs=tsc(L"Mw"),.name_ms=tsc(L"Mw")},.address={.postal_fmt=tsc(L"%z%c%T%s%b%e%r"),.country_name=tsc(L"Jabuuti"),.country_post=tsc(L"DJI"),.country_ab2=tsc(L"DJ"),.country_ab3=tsc(L"DJI"),.country_num=262,.country_car=tsc(L"DJI"),.lang_name=tsc(L"Soomaali"),.lang_ab=tsc(L"so"),.lang_term=tsc(L"som"),.lang_lib=tsc(L"som")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"so_DJ"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Somali language locale for Djibouti."),.source=tsc(u8"Ge'ez Frontier Foundation\t\t;\t\tufio"),.address=tsc(u8"7802 Solomon Seal Dr., Springfield, VA 22152, USA\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"locales@geez.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Somali"),.territory=tsc(u8"Djibouti"),.revision=tsc(u8"0.20"),.date=tsc(u8"2003-07-05")},.monetary={.int_curr_symbol=tsc(u8"DJF "),.currency_symbol=tsc(u8"Fdj"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8" "),.mon_grouping={monetary_mon_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8"")},.time={.abday={tsc(u8"Axd"),tsc(u8"Isn"),tsc(u8"Tal"),tsc(u8"Arb"),tsc(u8"Kha"),tsc(u8"Jim"),tsc(u8"Sab")},.day={tsc(u8"Axad"),tsc(u8"Isniin"),tsc(u8"Salaaso"),tsc(u8"Arbaco"),tsc(u8"Khamiis"),tsc(u8"Jimco"),tsc(u8"Sabti")},.abmon={tsc(u8"Kob"),tsc(u8"Lab"),tsc(u8"Sad"),tsc(u8"Afr"),tsc(u8"Sha"),tsc(u8"Lix"),tsc(u8"Tod"),tsc(u8"Sid"),tsc(u8"Sag"),tsc(u8"Tob"),tsc(u8"KIT"),tsc(u8"LIT")},.mon={tsc(u8"Bisha Koobaad"),tsc(u8"Bisha Labaad"),tsc(u8"Bisha Saddexaad"),tsc(u8"Bisha Afraad"),tsc(u8"Bisha Shanaad"),tsc(u8"Bisha Lixaad"),tsc(u8"Bisha Todobaad"),tsc(u8"Bisha Sideedaad"),tsc(u8"Bisha Sagaalaad"),tsc(u8"Bisha Tobnaad"),tsc(u8"Bisha Kow iyo Tobnaad"),tsc(u8"Bisha Laba iyo Tobnaad")},.d_t_fmt=tsc(u8"%a %d %b %Y %r %Z"),.d_fmt=tsc(u8"%d.%m.%Y"),.t_fmt=tsc(u8"%l:%M:%S %p"),.t_fmt_ampm=tsc(u8"%l:%M:%S %p"),.date_fmt=tsc(u8"%a %b %e %r %Z %Y"),.am_pm={tsc(u8"subaxnimo"),tsc(u8"galabnimo")},.week={7,19971130,1},.first_weekday=7},.messages={.yesexpr=tsc(u8"^[+1oOyY]"),.noexpr=tsc(u8"^[-0nN]"),.yesstr=tsc(u8"haa"),.nostr=tsc(u8"maya")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.tel_dom_fmt=tsc(u8"%a-%l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"253")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f"),.name_gen=tsc(u8""),.name_miss=tsc(u8""),.name_mr=tsc(u8"Md"),.name_mrs=tsc(u8"Mw"),.name_ms=tsc(u8"Mw")},.address={.postal_fmt=tsc(u8"%z%c%T%s%b%e%r"),.country_name=tsc(u8"Jabuuti"),.country_post=tsc(u8"DJI"),.country_ab2=tsc(u8"DJ"),.country_ab3=tsc(u8"DJI"),.country_num=262,.country_car=tsc(u8"DJI"),.lang_name=tsc(u8"Soomaali"),.lang_ab=tsc(u8"so"),.lang_term=tsc(u8"som"),.lang_lib=tsc(u8"som")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"so_DJ"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Somali language locale for Djibouti."),.source=tsc(u"Ge'ez Frontier Foundation\t\t;\t\tufio"),.address=tsc(u"7802 Solomon Seal Dr., Springfield, VA 22152, USA\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"locales@geez.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Somali"),.territory=tsc(u"Djibouti"),.revision=tsc(u"0.20"),.date=tsc(u"2003-07-05")},.monetary={.int_curr_symbol=tsc(u"DJF "),.currency_symbol=tsc(u"Fdj"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u" "),.mon_grouping={monetary_mon_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u"")},.time={.abday={tsc(u"Axd"),tsc(u"Isn"),tsc(u"Tal"),tsc(u"Arb"),tsc(u"Kha"),tsc(u"Jim"),tsc(u"Sab")},.day={tsc(u"Axad"),tsc(u"Isniin"),tsc(u"Salaaso"),tsc(u"Arbaco"),tsc(u"Khamiis"),tsc(u"Jimco"),tsc(u"Sabti")},.abmon={tsc(u"Kob"),tsc(u"Lab"),tsc(u"Sad"),tsc(u"Afr"),tsc(u"Sha"),tsc(u"Lix"),tsc(u"Tod"),tsc(u"Sid"),tsc(u"Sag"),tsc(u"Tob"),tsc(u"KIT"),tsc(u"LIT")},.mon={tsc(u"Bisha Koobaad"),tsc(u"Bisha Labaad"),tsc(u"Bisha Saddexaad"),tsc(u"Bisha Afraad"),tsc(u"Bisha Shanaad"),tsc(u"Bisha Lixaad"),tsc(u"Bisha Todobaad"),tsc(u"Bisha Sideedaad"),tsc(u"Bisha Sagaalaad"),tsc(u"Bisha Tobnaad"),tsc(u"Bisha Kow iyo Tobnaad"),tsc(u"Bisha Laba iyo Tobnaad")},.d_t_fmt=tsc(u"%a %d %b %Y %r %Z"),.d_fmt=tsc(u"%d.%m.%Y"),.t_fmt=tsc(u"%l:%M:%S %p"),.t_fmt_ampm=tsc(u"%l:%M:%S %p"),.date_fmt=tsc(u"%a %b %e %r %Z %Y"),.am_pm={tsc(u"subaxnimo"),tsc(u"galabnimo")},.week={7,19971130,1},.first_weekday=7},.messages={.yesexpr=tsc(u"^[+1oOyY]"),.noexpr=tsc(u"^[-0nN]"),.yesstr=tsc(u"haa"),.nostr=tsc(u"maya")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.tel_dom_fmt=tsc(u"%a-%l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"253")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f"),.name_gen=tsc(u""),.name_miss=tsc(u""),.name_mr=tsc(u"Md"),.name_mrs=tsc(u"Mw"),.name_ms=tsc(u"Mw")},.address={.postal_fmt=tsc(u"%z%c%T%s%b%e%r"),.country_name=tsc(u"Jabuuti"),.country_post=tsc(u"DJI"),.country_ab2=tsc(u"DJ"),.country_ab3=tsc(u"DJI"),.country_num=262,.country_car=tsc(u"DJI"),.lang_name=tsc(u"Soomaali"),.lang_ab=tsc(u"so"),.lang_term=tsc(u"som"),.lang_lib=tsc(u"som")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"so_DJ"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Somali language locale for Djibouti."),.source=tsc(U"Ge'ez Frontier Foundation\t\t;\t\tufio"),.address=tsc(U"7802 Solomon Seal Dr., Springfield, VA 22152, USA\t\t;\t\thttps://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"locales@geez.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Somali"),.territory=tsc(U"Djibouti"),.revision=tsc(U"0.20"),.date=tsc(U"2003-07-05")},.monetary={.int_curr_symbol=tsc(U"DJF "),.currency_symbol=tsc(U"Fdj"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U" "),.mon_grouping={monetary_mon_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U"")},.time={.abday={tsc(U"Axd"),tsc(U"Isn"),tsc(U"Tal"),tsc(U"Arb"),tsc(U"Kha"),tsc(U"Jim"),tsc(U"Sab")},.day={tsc(U"Axad"),tsc(U"Isniin"),tsc(U"Salaaso"),tsc(U"Arbaco"),tsc(U"Khamiis"),tsc(U"Jimco"),tsc(U"Sabti")},.abmon={tsc(U"Kob"),tsc(U"Lab"),tsc(U"Sad"),tsc(U"Afr"),tsc(U"Sha"),tsc(U"Lix"),tsc(U"Tod"),tsc(U"Sid"),tsc(U"Sag"),tsc(U"Tob"),tsc(U"KIT"),tsc(U"LIT")},.mon={tsc(U"Bisha Koobaad"),tsc(U"Bisha Labaad"),tsc(U"Bisha Saddexaad"),tsc(U"Bisha Afraad"),tsc(U"Bisha Shanaad"),tsc(U"Bisha Lixaad"),tsc(U"Bisha Todobaad"),tsc(U"Bisha Sideedaad"),tsc(U"Bisha Sagaalaad"),tsc(U"Bisha Tobnaad"),tsc(U"Bisha Kow iyo Tobnaad"),tsc(U"Bisha Laba iyo Tobnaad")},.d_t_fmt=tsc(U"%a %d %b %Y %r %Z"),.d_fmt=tsc(U"%d.%m.%Y"),.t_fmt=tsc(U"%l:%M:%S %p"),.t_fmt_ampm=tsc(U"%l:%M:%S %p"),.date_fmt=tsc(U"%a %b %e %r %Z %Y"),.am_pm={tsc(U"subaxnimo"),tsc(U"galabnimo")},.week={7,19971130,1},.first_weekday=7},.messages={.yesexpr=tsc(U"^[+1oOyY]"),.noexpr=tsc(U"^[-0nN]"),.yesstr=tsc(U"haa"),.nostr=tsc(U"maya")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.tel_dom_fmt=tsc(U"%a-%l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"253")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f"),.name_gen=tsc(U""),.name_miss=tsc(U""),.name_mr=tsc(U"Md"),.name_mrs=tsc(U"Mw"),.name_ms=tsc(U"Mw")},.address={.postal_fmt=tsc(U"%z%c%T%s%b%e%r"),.country_name=tsc(U"Jabuuti"),.country_post=tsc(U"DJI"),.country_ab2=tsc(U"DJ"),.country_ab3=tsc(U"DJI"),.country_num=262,.country_car=tsc(U"DJI"),.lang_name=tsc(U"Soomaali"),.lang_ab=tsc(U"so"),.lang_term=tsc(U"som"),.lang_lib=tsc(U"som")},.measurement={.measurement=1}};


}
}

#include"../main.h"