﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("tk_TM"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Turkmen locale for Turkmenistan"),.source=tsc("Ghorban M. Tavakoly\t\t;\t\tufio"),.address=tsc("https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("Pablo Saratxaga & Ghorban M. Tavakoly\t\t;\t\tufio"),.email=tsc("pablo@walon.org & gmt314@yahoo.com;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Turkmen"),.territory=tsc("Turkmenistan"),.revision=tsc("0.5"),.date=tsc("2011-04-09")},.monetary={.int_curr_symbol=tsc("TMM "),.currency_symbol=tsc("MANAT"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("Duş"),tsc("Siş"),tsc("Çar"),tsc("Pen"),tsc("Ann"),tsc("Şen"),tsc("Ýek")},.day={tsc("Duşenbe"),tsc("Sişenbe"),tsc("Çarşenbe"),tsc("Penşenbe"),tsc("Anna"),tsc("Şenbe"),tsc("Ýekşenbe")},.abmon={tsc("Ýan"),tsc("Few"),tsc("Mar"),tsc("Apr"),tsc("Maý"),tsc("Iýn"),tsc("Iýl"),tsc("Awg"),tsc("Sen"),tsc("Okt"),tsc("Noý"),tsc("Dek")},.mon={tsc("Ýanwar"),tsc("Fewral"),tsc("Mart"),tsc("Aprel"),tsc("Maý"),tsc("Iýun"),tsc("Iýul"),tsc("Awgust"),tsc("Sentýabr"),tsc("Oktýabr"),tsc("Noýabr"),tsc("Dekabr")},.d_t_fmt=tsc("%d.%m.%Y %T"),.d_fmt=tsc("%d.%m.%Y"),.t_fmt=tsc("%T"),.t_fmt_ampm=tsc(""),.date_fmt=tsc("%d.%m.%Y %T %Z"),.am_pm={tsc(""),tsc("")},.week={7,19971130,1},.first_weekday=2},.messages={.yesexpr=tsc("^[+1hH]"),.noexpr=tsc("^[-0nNýÝ]"),.yesstr=tsc("hawa"),.nostr=tsc("ýok")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("8 10"),.int_prefix=tsc("993")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f"),.name_gen=tsc(""),.name_miss=tsc(""),.name_mr=tsc(""),.name_mrs=tsc(""),.name_ms=tsc("")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Türkmenistan"),.country_post=tsc("TM"),.country_ab2=tsc("TM"),.country_ab3=tsc("TKM"),.country_num=795,.country_car=tsc("TM"),.lang_name=tsc("türkmen dili"),.lang_ab=tsc("tk"),.lang_term=tsc("tuk"),.lang_lib=tsc("tuk")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"tk_TM"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Turkmen locale for Turkmenistan"),.source=tsc(L"Ghorban M. Tavakoly\t\t;\t\tufio"),.address=tsc(L"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"Pablo Saratxaga & Ghorban M. Tavakoly\t\t;\t\tufio"),.email=tsc(L"pablo@walon.org & gmt314@yahoo.com;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Turkmen"),.territory=tsc(L"Turkmenistan"),.revision=tsc(L"0.5"),.date=tsc(L"2011-04-09")},.monetary={.int_curr_symbol=tsc(L"TMM "),.currency_symbol=tsc(L"MANAT"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"Duş"),tsc(L"Siş"),tsc(L"Çar"),tsc(L"Pen"),tsc(L"Ann"),tsc(L"Şen"),tsc(L"Ýek")},.day={tsc(L"Duşenbe"),tsc(L"Sişenbe"),tsc(L"Çarşenbe"),tsc(L"Penşenbe"),tsc(L"Anna"),tsc(L"Şenbe"),tsc(L"Ýekşenbe")},.abmon={tsc(L"Ýan"),tsc(L"Few"),tsc(L"Mar"),tsc(L"Apr"),tsc(L"Maý"),tsc(L"Iýn"),tsc(L"Iýl"),tsc(L"Awg"),tsc(L"Sen"),tsc(L"Okt"),tsc(L"Noý"),tsc(L"Dek")},.mon={tsc(L"Ýanwar"),tsc(L"Fewral"),tsc(L"Mart"),tsc(L"Aprel"),tsc(L"Maý"),tsc(L"Iýun"),tsc(L"Iýul"),tsc(L"Awgust"),tsc(L"Sentýabr"),tsc(L"Oktýabr"),tsc(L"Noýabr"),tsc(L"Dekabr")},.d_t_fmt=tsc(L"%d.%m.%Y %T"),.d_fmt=tsc(L"%d.%m.%Y"),.t_fmt=tsc(L"%T"),.t_fmt_ampm=tsc(L""),.date_fmt=tsc(L"%d.%m.%Y %T %Z"),.am_pm={tsc(L""),tsc(L"")},.week={7,19971130,1},.first_weekday=2},.messages={.yesexpr=tsc(L"^[+1hH]"),.noexpr=tsc(L"^[-0nNýÝ]"),.yesstr=tsc(L"hawa"),.nostr=tsc(L"ýok")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"8 10"),.int_prefix=tsc(L"993")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f"),.name_gen=tsc(L""),.name_miss=tsc(L""),.name_mr=tsc(L""),.name_mrs=tsc(L""),.name_ms=tsc(L"")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Türkmenistan"),.country_post=tsc(L"TM"),.country_ab2=tsc(L"TM"),.country_ab3=tsc(L"TKM"),.country_num=795,.country_car=tsc(L"TM"),.lang_name=tsc(L"türkmen dili"),.lang_ab=tsc(L"tk"),.lang_term=tsc(L"tuk"),.lang_lib=tsc(L"tuk")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"tk_TM"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Turkmen locale for Turkmenistan"),.source=tsc(u8"Ghorban M. Tavakoly\t\t;\t\tufio"),.address=tsc(u8"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"Pablo Saratxaga & Ghorban M. Tavakoly\t\t;\t\tufio"),.email=tsc(u8"pablo@walon.org & gmt314@yahoo.com;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Turkmen"),.territory=tsc(u8"Turkmenistan"),.revision=tsc(u8"0.5"),.date=tsc(u8"2011-04-09")},.monetary={.int_curr_symbol=tsc(u8"TMM "),.currency_symbol=tsc(u8"MANAT"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"Duş"),tsc(u8"Siş"),tsc(u8"Çar"),tsc(u8"Pen"),tsc(u8"Ann"),tsc(u8"Şen"),tsc(u8"Ýek")},.day={tsc(u8"Duşenbe"),tsc(u8"Sişenbe"),tsc(u8"Çarşenbe"),tsc(u8"Penşenbe"),tsc(u8"Anna"),tsc(u8"Şenbe"),tsc(u8"Ýekşenbe")},.abmon={tsc(u8"Ýan"),tsc(u8"Few"),tsc(u8"Mar"),tsc(u8"Apr"),tsc(u8"Maý"),tsc(u8"Iýn"),tsc(u8"Iýl"),tsc(u8"Awg"),tsc(u8"Sen"),tsc(u8"Okt"),tsc(u8"Noý"),tsc(u8"Dek")},.mon={tsc(u8"Ýanwar"),tsc(u8"Fewral"),tsc(u8"Mart"),tsc(u8"Aprel"),tsc(u8"Maý"),tsc(u8"Iýun"),tsc(u8"Iýul"),tsc(u8"Awgust"),tsc(u8"Sentýabr"),tsc(u8"Oktýabr"),tsc(u8"Noýabr"),tsc(u8"Dekabr")},.d_t_fmt=tsc(u8"%d.%m.%Y %T"),.d_fmt=tsc(u8"%d.%m.%Y"),.t_fmt=tsc(u8"%T"),.t_fmt_ampm=tsc(u8""),.date_fmt=tsc(u8"%d.%m.%Y %T %Z"),.am_pm={tsc(u8""),tsc(u8"")},.week={7,19971130,1},.first_weekday=2},.messages={.yesexpr=tsc(u8"^[+1hH]"),.noexpr=tsc(u8"^[-0nNýÝ]"),.yesstr=tsc(u8"hawa"),.nostr=tsc(u8"ýok")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"8 10"),.int_prefix=tsc(u8"993")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f"),.name_gen=tsc(u8""),.name_miss=tsc(u8""),.name_mr=tsc(u8""),.name_mrs=tsc(u8""),.name_ms=tsc(u8"")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Türkmenistan"),.country_post=tsc(u8"TM"),.country_ab2=tsc(u8"TM"),.country_ab3=tsc(u8"TKM"),.country_num=795,.country_car=tsc(u8"TM"),.lang_name=tsc(u8"türkmen dili"),.lang_ab=tsc(u8"tk"),.lang_term=tsc(u8"tuk"),.lang_lib=tsc(u8"tuk")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"tk_TM"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Turkmen locale for Turkmenistan"),.source=tsc(u"Ghorban M. Tavakoly\t\t;\t\tufio"),.address=tsc(u"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"Pablo Saratxaga & Ghorban M. Tavakoly\t\t;\t\tufio"),.email=tsc(u"pablo@walon.org & gmt314@yahoo.com;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Turkmen"),.territory=tsc(u"Turkmenistan"),.revision=tsc(u"0.5"),.date=tsc(u"2011-04-09")},.monetary={.int_curr_symbol=tsc(u"TMM "),.currency_symbol=tsc(u"MANAT"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"Duş"),tsc(u"Siş"),tsc(u"Çar"),tsc(u"Pen"),tsc(u"Ann"),tsc(u"Şen"),tsc(u"Ýek")},.day={tsc(u"Duşenbe"),tsc(u"Sişenbe"),tsc(u"Çarşenbe"),tsc(u"Penşenbe"),tsc(u"Anna"),tsc(u"Şenbe"),tsc(u"Ýekşenbe")},.abmon={tsc(u"Ýan"),tsc(u"Few"),tsc(u"Mar"),tsc(u"Apr"),tsc(u"Maý"),tsc(u"Iýn"),tsc(u"Iýl"),tsc(u"Awg"),tsc(u"Sen"),tsc(u"Okt"),tsc(u"Noý"),tsc(u"Dek")},.mon={tsc(u"Ýanwar"),tsc(u"Fewral"),tsc(u"Mart"),tsc(u"Aprel"),tsc(u"Maý"),tsc(u"Iýun"),tsc(u"Iýul"),tsc(u"Awgust"),tsc(u"Sentýabr"),tsc(u"Oktýabr"),tsc(u"Noýabr"),tsc(u"Dekabr")},.d_t_fmt=tsc(u"%d.%m.%Y %T"),.d_fmt=tsc(u"%d.%m.%Y"),.t_fmt=tsc(u"%T"),.t_fmt_ampm=tsc(u""),.date_fmt=tsc(u"%d.%m.%Y %T %Z"),.am_pm={tsc(u""),tsc(u"")},.week={7,19971130,1},.first_weekday=2},.messages={.yesexpr=tsc(u"^[+1hH]"),.noexpr=tsc(u"^[-0nNýÝ]"),.yesstr=tsc(u"hawa"),.nostr=tsc(u"ýok")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"8 10"),.int_prefix=tsc(u"993")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f"),.name_gen=tsc(u""),.name_miss=tsc(u""),.name_mr=tsc(u""),.name_mrs=tsc(u""),.name_ms=tsc(u"")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Türkmenistan"),.country_post=tsc(u"TM"),.country_ab2=tsc(u"TM"),.country_ab3=tsc(u"TKM"),.country_num=795,.country_car=tsc(u"TM"),.lang_name=tsc(u"türkmen dili"),.lang_ab=tsc(u"tk"),.lang_term=tsc(u"tuk"),.lang_lib=tsc(u"tuk")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"tk_TM"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Turkmen locale for Turkmenistan"),.source=tsc(U"Ghorban M. Tavakoly\t\t;\t\tufio"),.address=tsc(U"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"Pablo Saratxaga & Ghorban M. Tavakoly\t\t;\t\tufio"),.email=tsc(U"pablo@walon.org & gmt314@yahoo.com;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Turkmen"),.territory=tsc(U"Turkmenistan"),.revision=tsc(U"0.5"),.date=tsc(U"2011-04-09")},.monetary={.int_curr_symbol=tsc(U"TMM "),.currency_symbol=tsc(U"MANAT"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"Duş"),tsc(U"Siş"),tsc(U"Çar"),tsc(U"Pen"),tsc(U"Ann"),tsc(U"Şen"),tsc(U"Ýek")},.day={tsc(U"Duşenbe"),tsc(U"Sişenbe"),tsc(U"Çarşenbe"),tsc(U"Penşenbe"),tsc(U"Anna"),tsc(U"Şenbe"),tsc(U"Ýekşenbe")},.abmon={tsc(U"Ýan"),tsc(U"Few"),tsc(U"Mar"),tsc(U"Apr"),tsc(U"Maý"),tsc(U"Iýn"),tsc(U"Iýl"),tsc(U"Awg"),tsc(U"Sen"),tsc(U"Okt"),tsc(U"Noý"),tsc(U"Dek")},.mon={tsc(U"Ýanwar"),tsc(U"Fewral"),tsc(U"Mart"),tsc(U"Aprel"),tsc(U"Maý"),tsc(U"Iýun"),tsc(U"Iýul"),tsc(U"Awgust"),tsc(U"Sentýabr"),tsc(U"Oktýabr"),tsc(U"Noýabr"),tsc(U"Dekabr")},.d_t_fmt=tsc(U"%d.%m.%Y %T"),.d_fmt=tsc(U"%d.%m.%Y"),.t_fmt=tsc(U"%T"),.t_fmt_ampm=tsc(U""),.date_fmt=tsc(U"%d.%m.%Y %T %Z"),.am_pm={tsc(U""),tsc(U"")},.week={7,19971130,1},.first_weekday=2},.messages={.yesexpr=tsc(U"^[+1hH]"),.noexpr=tsc(U"^[-0nNýÝ]"),.yesstr=tsc(U"hawa"),.nostr=tsc(U"ýok")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"8 10"),.int_prefix=tsc(U"993")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f"),.name_gen=tsc(U""),.name_miss=tsc(U""),.name_mr=tsc(U""),.name_mrs=tsc(U""),.name_ms=tsc(U"")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Türkmenistan"),.country_post=tsc(U"TM"),.country_ab2=tsc(U"TM"),.country_ab3=tsc(U"TKM"),.country_num=795,.country_car=tsc(U"TM"),.lang_name=tsc(U"türkmen dili"),.lang_ab=tsc(U"tk"),.lang_term=tsc(U"tuk"),.lang_lib=tsc(U"tuk")},.measurement={.measurement=1}};


}
}

#include"../main.h"