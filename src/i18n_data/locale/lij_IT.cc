﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("lij_IT"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Ligurian locale for Italy"),.source=tsc("Gastaldi\t\t;\t\tufio"),.address=tsc("https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("alessio.gastaldi@libero.it;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Ligurian"),.territory=tsc("Italy"),.revision=tsc("1.0"),.date=tsc("2010-10-22")},.monetary={.int_curr_symbol=tsc("EUR "),.currency_symbol=tsc("€"),.mon_decimal_point=tsc(","),.mon_thousands_sep=tsc("."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(","),.thousands_sep=tsc("."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("dom"),tsc("lûn"),tsc("mar"),tsc("mer"),tsc("zêu"),tsc("ven"),tsc("sab")},.day={tsc("domenega"),tsc("lûnedì"),tsc("martedì"),tsc("mercUrdì"),tsc("zêggia"),tsc("venardì"),tsc("sabbo")},.abmon={tsc("zen"),tsc("fev"),tsc("mar"),tsc("arv"),tsc("maz"),tsc("zûg"),tsc("lûg"),tsc("ago"),tsc("set"),tsc("ött"),tsc("nov"),tsc("dix")},.mon={tsc("zenâ"),tsc("fevrâ"),tsc("marzo"),tsc("avrî"),tsc("mazzo"),tsc("zûgno"),tsc("lûggio"),tsc("agosto"),tsc("settembre"),tsc("ottobre"),tsc("novembre"),tsc("dixembre")},.d_t_fmt=tsc("%a %d %b %Y %T %Z"),.d_fmt=tsc("%d//%m//%Y"),.t_fmt=tsc("%T"),.t_fmt_ampm=tsc(""),.date_fmt=tsc("%a %e %b %Y, %H.%M.%S, %Z"),.am_pm={tsc(""),tsc("")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc("^[+1sSyY]"),.noexpr=tsc("^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("00"),.int_prefix=tsc("39")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Italia"),.country_ab2=tsc("IT"),.country_ab3=tsc("ITA"),.country_num=380,.country_car=tsc("I"),.country_isbn=tsc("978-88,979-12"),.lang_name=tsc("Lìgure"),.lang_term=tsc("lij"),.lang_lib=tsc("lij")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"lij_IT"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Ligurian locale for Italy"),.source=tsc(L"Gastaldi\t\t;\t\tufio"),.address=tsc(L"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"alessio.gastaldi@libero.it;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Ligurian"),.territory=tsc(L"Italy"),.revision=tsc(L"1.0"),.date=tsc(L"2010-10-22")},.monetary={.int_curr_symbol=tsc(L"EUR "),.currency_symbol=tsc(L"€"),.mon_decimal_point=tsc(L","),.mon_thousands_sep=tsc(L"."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L","),.thousands_sep=tsc(L"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"dom"),tsc(L"lûn"),tsc(L"mar"),tsc(L"mer"),tsc(L"zêu"),tsc(L"ven"),tsc(L"sab")},.day={tsc(L"domenega"),tsc(L"lûnedì"),tsc(L"martedì"),tsc(L"mercUrdì"),tsc(L"zêggia"),tsc(L"venardì"),tsc(L"sabbo")},.abmon={tsc(L"zen"),tsc(L"fev"),tsc(L"mar"),tsc(L"arv"),tsc(L"maz"),tsc(L"zûg"),tsc(L"lûg"),tsc(L"ago"),tsc(L"set"),tsc(L"ött"),tsc(L"nov"),tsc(L"dix")},.mon={tsc(L"zenâ"),tsc(L"fevrâ"),tsc(L"marzo"),tsc(L"avrî"),tsc(L"mazzo"),tsc(L"zûgno"),tsc(L"lûggio"),tsc(L"agosto"),tsc(L"settembre"),tsc(L"ottobre"),tsc(L"novembre"),tsc(L"dixembre")},.d_t_fmt=tsc(L"%a %d %b %Y %T %Z"),.d_fmt=tsc(L"%d//%m//%Y"),.t_fmt=tsc(L"%T"),.t_fmt_ampm=tsc(L""),.date_fmt=tsc(L"%a %e %b %Y, %H.%M.%S, %Z"),.am_pm={tsc(L""),tsc(L"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(L"^[+1sSyY]"),.noexpr=tsc(L"^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"39")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Italia"),.country_ab2=tsc(L"IT"),.country_ab3=tsc(L"ITA"),.country_num=380,.country_car=tsc(L"I"),.country_isbn=tsc(L"978-88,979-12"),.lang_name=tsc(L"Lìgure"),.lang_term=tsc(L"lij"),.lang_lib=tsc(L"lij")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"lij_IT"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Ligurian locale for Italy"),.source=tsc(u8"Gastaldi\t\t;\t\tufio"),.address=tsc(u8"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"alessio.gastaldi@libero.it;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Ligurian"),.territory=tsc(u8"Italy"),.revision=tsc(u8"1.0"),.date=tsc(u8"2010-10-22")},.monetary={.int_curr_symbol=tsc(u8"EUR "),.currency_symbol=tsc(u8"€"),.mon_decimal_point=tsc(u8","),.mon_thousands_sep=tsc(u8"."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8","),.thousands_sep=tsc(u8"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"dom"),tsc(u8"lûn"),tsc(u8"mar"),tsc(u8"mer"),tsc(u8"zêu"),tsc(u8"ven"),tsc(u8"sab")},.day={tsc(u8"domenega"),tsc(u8"lûnedì"),tsc(u8"martedì"),tsc(u8"mercUrdì"),tsc(u8"zêggia"),tsc(u8"venardì"),tsc(u8"sabbo")},.abmon={tsc(u8"zen"),tsc(u8"fev"),tsc(u8"mar"),tsc(u8"arv"),tsc(u8"maz"),tsc(u8"zûg"),tsc(u8"lûg"),tsc(u8"ago"),tsc(u8"set"),tsc(u8"ött"),tsc(u8"nov"),tsc(u8"dix")},.mon={tsc(u8"zenâ"),tsc(u8"fevrâ"),tsc(u8"marzo"),tsc(u8"avrî"),tsc(u8"mazzo"),tsc(u8"zûgno"),tsc(u8"lûggio"),tsc(u8"agosto"),tsc(u8"settembre"),tsc(u8"ottobre"),tsc(u8"novembre"),tsc(u8"dixembre")},.d_t_fmt=tsc(u8"%a %d %b %Y %T %Z"),.d_fmt=tsc(u8"%d//%m//%Y"),.t_fmt=tsc(u8"%T"),.t_fmt_ampm=tsc(u8""),.date_fmt=tsc(u8"%a %e %b %Y, %H.%M.%S, %Z"),.am_pm={tsc(u8""),tsc(u8"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u8"^[+1sSyY]"),.noexpr=tsc(u8"^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"39")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Italia"),.country_ab2=tsc(u8"IT"),.country_ab3=tsc(u8"ITA"),.country_num=380,.country_car=tsc(u8"I"),.country_isbn=tsc(u8"978-88,979-12"),.lang_name=tsc(u8"Lìgure"),.lang_term=tsc(u8"lij"),.lang_lib=tsc(u8"lij")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"lij_IT"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Ligurian locale for Italy"),.source=tsc(u"Gastaldi\t\t;\t\tufio"),.address=tsc(u"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"alessio.gastaldi@libero.it;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Ligurian"),.territory=tsc(u"Italy"),.revision=tsc(u"1.0"),.date=tsc(u"2010-10-22")},.monetary={.int_curr_symbol=tsc(u"EUR "),.currency_symbol=tsc(u"€"),.mon_decimal_point=tsc(u","),.mon_thousands_sep=tsc(u"."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u","),.thousands_sep=tsc(u"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"dom"),tsc(u"lûn"),tsc(u"mar"),tsc(u"mer"),tsc(u"zêu"),tsc(u"ven"),tsc(u"sab")},.day={tsc(u"domenega"),tsc(u"lûnedì"),tsc(u"martedì"),tsc(u"mercUrdì"),tsc(u"zêggia"),tsc(u"venardì"),tsc(u"sabbo")},.abmon={tsc(u"zen"),tsc(u"fev"),tsc(u"mar"),tsc(u"arv"),tsc(u"maz"),tsc(u"zûg"),tsc(u"lûg"),tsc(u"ago"),tsc(u"set"),tsc(u"ött"),tsc(u"nov"),tsc(u"dix")},.mon={tsc(u"zenâ"),tsc(u"fevrâ"),tsc(u"marzo"),tsc(u"avrî"),tsc(u"mazzo"),tsc(u"zûgno"),tsc(u"lûggio"),tsc(u"agosto"),tsc(u"settembre"),tsc(u"ottobre"),tsc(u"novembre"),tsc(u"dixembre")},.d_t_fmt=tsc(u"%a %d %b %Y %T %Z"),.d_fmt=tsc(u"%d//%m//%Y"),.t_fmt=tsc(u"%T"),.t_fmt_ampm=tsc(u""),.date_fmt=tsc(u"%a %e %b %Y, %H.%M.%S, %Z"),.am_pm={tsc(u""),tsc(u"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u"^[+1sSyY]"),.noexpr=tsc(u"^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"39")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Italia"),.country_ab2=tsc(u"IT"),.country_ab3=tsc(u"ITA"),.country_num=380,.country_car=tsc(u"I"),.country_isbn=tsc(u"978-88,979-12"),.lang_name=tsc(u"Lìgure"),.lang_term=tsc(u"lij"),.lang_lib=tsc(u"lij")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"lij_IT"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Ligurian locale for Italy"),.source=tsc(U"Gastaldi\t\t;\t\tufio"),.address=tsc(U"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"alessio.gastaldi@libero.it;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Ligurian"),.territory=tsc(U"Italy"),.revision=tsc(U"1.0"),.date=tsc(U"2010-10-22")},.monetary={.int_curr_symbol=tsc(U"EUR "),.currency_symbol=tsc(U"€"),.mon_decimal_point=tsc(U","),.mon_thousands_sep=tsc(U"."),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U","),.thousands_sep=tsc(U"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"dom"),tsc(U"lûn"),tsc(U"mar"),tsc(U"mer"),tsc(U"zêu"),tsc(U"ven"),tsc(U"sab")},.day={tsc(U"domenega"),tsc(U"lûnedì"),tsc(U"martedì"),tsc(U"mercUrdì"),tsc(U"zêggia"),tsc(U"venardì"),tsc(U"sabbo")},.abmon={tsc(U"zen"),tsc(U"fev"),tsc(U"mar"),tsc(U"arv"),tsc(U"maz"),tsc(U"zûg"),tsc(U"lûg"),tsc(U"ago"),tsc(U"set"),tsc(U"ött"),tsc(U"nov"),tsc(U"dix")},.mon={tsc(U"zenâ"),tsc(U"fevrâ"),tsc(U"marzo"),tsc(U"avrî"),tsc(U"mazzo"),tsc(U"zûgno"),tsc(U"lûggio"),tsc(U"agosto"),tsc(U"settembre"),tsc(U"ottobre"),tsc(U"novembre"),tsc(U"dixembre")},.d_t_fmt=tsc(U"%a %d %b %Y %T %Z"),.d_fmt=tsc(U"%d//%m//%Y"),.t_fmt=tsc(U"%T"),.t_fmt_ampm=tsc(U""),.date_fmt=tsc(U"%a %e %b %Y, %H.%M.%S, %Z"),.am_pm={tsc(U""),tsc(U"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(U"^[+1sSyY]"),.noexpr=tsc(U"^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"39")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Italia"),.country_ab2=tsc(U"IT"),.country_ab3=tsc(U"ITA"),.country_num=380,.country_car=tsc(U"I"),.country_isbn=tsc(U"978-88,979-12"),.lang_name=tsc(U"Lìgure"),.lang_term=tsc(U"lij"),.lang_lib=tsc(U"lij")},.measurement={.measurement=1}};


}
}

#include"../main.h"