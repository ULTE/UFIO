﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("agr_PE"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Awajún (agr) locale for Peru"),.source=tsc("somosazucar.org\t\t;\t\tufio"),.address=tsc("https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Aguaruna"),.territory=tsc("Peru"),.revision=tsc("1.0"),.date=tsc("2016-08-20")},.monetary={.int_curr_symbol=tsc("PEN "),.currency_symbol=tsc("S//"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(","),.thousands_sep=tsc("."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("Tun"),tsc("Ach"),tsc("Kug"),tsc("Sak"),tsc("Shim"),tsc("Im"),tsc("Bat")},.day={tsc("Tuntuamtin"),tsc("Achutin"),tsc("Kugkuktin"),tsc("Saketin"),tsc("Shimpitin"),tsc("Imaptin"),tsc("Bataetin")},.abmon={tsc("Pet"),tsc("Kup"),tsc("Uya"),tsc("Tay"),tsc("Keg"),tsc("Teg"),tsc("Kun"),tsc("Yag"),tsc("Dait"),tsc("Ipam"),tsc("Shin"),tsc("Sak")},.mon={tsc("Petsatin"),tsc("Kupitin"),tsc("Uyaitin"),tsc("Tayutin"),tsc("Kegketin"),tsc("Tegmatin"),tsc("Kuntutin"),tsc("Yagkujutin"),tsc("Daiktatin"),tsc("Ipamtatin"),tsc("Shinutin"),tsc("Sakamtin")},.d_t_fmt=tsc("%a %d %b %Y %T %Z"),.d_fmt=tsc("%d//%m//%y"),.t_fmt=tsc("%T"),.t_fmt_ampm=tsc("%I:%M:%S %p"),.date_fmt=tsc("%a %b %e %H:%M:%S %Z %Y"),.am_pm={tsc("VM"),tsc("NM")},.week={7,19971130,7},.first_weekday=1,.first_workday=2},.messages={.yesexpr=tsc("^[+1eEsSyY]"),.noexpr=tsc("^[-0aAnN]"),.yesstr=tsc("ehe"),.nostr=tsc("atsa")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("00"),.int_prefix=tsc("51")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Perú"),.country_ab2=tsc("PE"),.country_ab3=tsc("PER"),.country_num=604,.country_car=tsc("PE"),.lang_name=tsc("Awajún"),.lang_ab=tsc(""),.lang_term=tsc(""),.lang_lib=tsc("agr")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"agr_PE"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Awajún (agr) locale for Peru"),.source=tsc(L"somosazucar.org\t\t;\t\tufio"),.address=tsc(L"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Aguaruna"),.territory=tsc(L"Peru"),.revision=tsc(L"1.0"),.date=tsc(L"2016-08-20")},.monetary={.int_curr_symbol=tsc(L"PEN "),.currency_symbol=tsc(L"S//"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L","),.thousands_sep=tsc(L"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"Tun"),tsc(L"Ach"),tsc(L"Kug"),tsc(L"Sak"),tsc(L"Shim"),tsc(L"Im"),tsc(L"Bat")},.day={tsc(L"Tuntuamtin"),tsc(L"Achutin"),tsc(L"Kugkuktin"),tsc(L"Saketin"),tsc(L"Shimpitin"),tsc(L"Imaptin"),tsc(L"Bataetin")},.abmon={tsc(L"Pet"),tsc(L"Kup"),tsc(L"Uya"),tsc(L"Tay"),tsc(L"Keg"),tsc(L"Teg"),tsc(L"Kun"),tsc(L"Yag"),tsc(L"Dait"),tsc(L"Ipam"),tsc(L"Shin"),tsc(L"Sak")},.mon={tsc(L"Petsatin"),tsc(L"Kupitin"),tsc(L"Uyaitin"),tsc(L"Tayutin"),tsc(L"Kegketin"),tsc(L"Tegmatin"),tsc(L"Kuntutin"),tsc(L"Yagkujutin"),tsc(L"Daiktatin"),tsc(L"Ipamtatin"),tsc(L"Shinutin"),tsc(L"Sakamtin")},.d_t_fmt=tsc(L"%a %d %b %Y %T %Z"),.d_fmt=tsc(L"%d//%m//%y"),.t_fmt=tsc(L"%T"),.t_fmt_ampm=tsc(L"%I:%M:%S %p"),.date_fmt=tsc(L"%a %b %e %H:%M:%S %Z %Y"),.am_pm={tsc(L"VM"),tsc(L"NM")},.week={7,19971130,7},.first_weekday=1,.first_workday=2},.messages={.yesexpr=tsc(L"^[+1eEsSyY]"),.noexpr=tsc(L"^[-0aAnN]"),.yesstr=tsc(L"ehe"),.nostr=tsc(L"atsa")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"51")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Perú"),.country_ab2=tsc(L"PE"),.country_ab3=tsc(L"PER"),.country_num=604,.country_car=tsc(L"PE"),.lang_name=tsc(L"Awajún"),.lang_ab=tsc(L""),.lang_term=tsc(L""),.lang_lib=tsc(L"agr")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"agr_PE"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Awajún (agr) locale for Peru"),.source=tsc(u8"somosazucar.org\t\t;\t\tufio"),.address=tsc(u8"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Aguaruna"),.territory=tsc(u8"Peru"),.revision=tsc(u8"1.0"),.date=tsc(u8"2016-08-20")},.monetary={.int_curr_symbol=tsc(u8"PEN "),.currency_symbol=tsc(u8"S//"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8","),.thousands_sep=tsc(u8"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"Tun"),tsc(u8"Ach"),tsc(u8"Kug"),tsc(u8"Sak"),tsc(u8"Shim"),tsc(u8"Im"),tsc(u8"Bat")},.day={tsc(u8"Tuntuamtin"),tsc(u8"Achutin"),tsc(u8"Kugkuktin"),tsc(u8"Saketin"),tsc(u8"Shimpitin"),tsc(u8"Imaptin"),tsc(u8"Bataetin")},.abmon={tsc(u8"Pet"),tsc(u8"Kup"),tsc(u8"Uya"),tsc(u8"Tay"),tsc(u8"Keg"),tsc(u8"Teg"),tsc(u8"Kun"),tsc(u8"Yag"),tsc(u8"Dait"),tsc(u8"Ipam"),tsc(u8"Shin"),tsc(u8"Sak")},.mon={tsc(u8"Petsatin"),tsc(u8"Kupitin"),tsc(u8"Uyaitin"),tsc(u8"Tayutin"),tsc(u8"Kegketin"),tsc(u8"Tegmatin"),tsc(u8"Kuntutin"),tsc(u8"Yagkujutin"),tsc(u8"Daiktatin"),tsc(u8"Ipamtatin"),tsc(u8"Shinutin"),tsc(u8"Sakamtin")},.d_t_fmt=tsc(u8"%a %d %b %Y %T %Z"),.d_fmt=tsc(u8"%d//%m//%y"),.t_fmt=tsc(u8"%T"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p"),.date_fmt=tsc(u8"%a %b %e %H:%M:%S %Z %Y"),.am_pm={tsc(u8"VM"),tsc(u8"NM")},.week={7,19971130,7},.first_weekday=1,.first_workday=2},.messages={.yesexpr=tsc(u8"^[+1eEsSyY]"),.noexpr=tsc(u8"^[-0aAnN]"),.yesstr=tsc(u8"ehe"),.nostr=tsc(u8"atsa")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"51")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Perú"),.country_ab2=tsc(u8"PE"),.country_ab3=tsc(u8"PER"),.country_num=604,.country_car=tsc(u8"PE"),.lang_name=tsc(u8"Awajún"),.lang_ab=tsc(u8""),.lang_term=tsc(u8""),.lang_lib=tsc(u8"agr")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"agr_PE"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Awajún (agr) locale for Peru"),.source=tsc(u"somosazucar.org\t\t;\t\tufio"),.address=tsc(u"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Aguaruna"),.territory=tsc(u"Peru"),.revision=tsc(u"1.0"),.date=tsc(u"2016-08-20")},.monetary={.int_curr_symbol=tsc(u"PEN "),.currency_symbol=tsc(u"S//"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u","),.thousands_sep=tsc(u"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"Tun"),tsc(u"Ach"),tsc(u"Kug"),tsc(u"Sak"),tsc(u"Shim"),tsc(u"Im"),tsc(u"Bat")},.day={tsc(u"Tuntuamtin"),tsc(u"Achutin"),tsc(u"Kugkuktin"),tsc(u"Saketin"),tsc(u"Shimpitin"),tsc(u"Imaptin"),tsc(u"Bataetin")},.abmon={tsc(u"Pet"),tsc(u"Kup"),tsc(u"Uya"),tsc(u"Tay"),tsc(u"Keg"),tsc(u"Teg"),tsc(u"Kun"),tsc(u"Yag"),tsc(u"Dait"),tsc(u"Ipam"),tsc(u"Shin"),tsc(u"Sak")},.mon={tsc(u"Petsatin"),tsc(u"Kupitin"),tsc(u"Uyaitin"),tsc(u"Tayutin"),tsc(u"Kegketin"),tsc(u"Tegmatin"),tsc(u"Kuntutin"),tsc(u"Yagkujutin"),tsc(u"Daiktatin"),tsc(u"Ipamtatin"),tsc(u"Shinutin"),tsc(u"Sakamtin")},.d_t_fmt=tsc(u"%a %d %b %Y %T %Z"),.d_fmt=tsc(u"%d//%m//%y"),.t_fmt=tsc(u"%T"),.t_fmt_ampm=tsc(u"%I:%M:%S %p"),.date_fmt=tsc(u"%a %b %e %H:%M:%S %Z %Y"),.am_pm={tsc(u"VM"),tsc(u"NM")},.week={7,19971130,7},.first_weekday=1,.first_workday=2},.messages={.yesexpr=tsc(u"^[+1eEsSyY]"),.noexpr=tsc(u"^[-0aAnN]"),.yesstr=tsc(u"ehe"),.nostr=tsc(u"atsa")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"51")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Perú"),.country_ab2=tsc(u"PE"),.country_ab3=tsc(u"PER"),.country_num=604,.country_car=tsc(u"PE"),.lang_name=tsc(u"Awajún"),.lang_ab=tsc(u""),.lang_term=tsc(u""),.lang_lib=tsc(u"agr")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"agr_PE"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Awajún (agr) locale for Peru"),.source=tsc(U"somosazucar.org\t\t;\t\tufio"),.address=tsc(U"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"libc-alpha@sourceware.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Aguaruna"),.territory=tsc(U"Peru"),.revision=tsc(U"1.0"),.date=tsc(U"2016-08-20")},.monetary={.int_curr_symbol=tsc(U"PEN "),.currency_symbol=tsc(U"S//"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=1,.n_cs_precedes=1,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U","),.thousands_sep=tsc(U"."),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"Tun"),tsc(U"Ach"),tsc(U"Kug"),tsc(U"Sak"),tsc(U"Shim"),tsc(U"Im"),tsc(U"Bat")},.day={tsc(U"Tuntuamtin"),tsc(U"Achutin"),tsc(U"Kugkuktin"),tsc(U"Saketin"),tsc(U"Shimpitin"),tsc(U"Imaptin"),tsc(U"Bataetin")},.abmon={tsc(U"Pet"),tsc(U"Kup"),tsc(U"Uya"),tsc(U"Tay"),tsc(U"Keg"),tsc(U"Teg"),tsc(U"Kun"),tsc(U"Yag"),tsc(U"Dait"),tsc(U"Ipam"),tsc(U"Shin"),tsc(U"Sak")},.mon={tsc(U"Petsatin"),tsc(U"Kupitin"),tsc(U"Uyaitin"),tsc(U"Tayutin"),tsc(U"Kegketin"),tsc(U"Tegmatin"),tsc(U"Kuntutin"),tsc(U"Yagkujutin"),tsc(U"Daiktatin"),tsc(U"Ipamtatin"),tsc(U"Shinutin"),tsc(U"Sakamtin")},.d_t_fmt=tsc(U"%a %d %b %Y %T %Z"),.d_fmt=tsc(U"%d//%m//%y"),.t_fmt=tsc(U"%T"),.t_fmt_ampm=tsc(U"%I:%M:%S %p"),.date_fmt=tsc(U"%a %b %e %H:%M:%S %Z %Y"),.am_pm={tsc(U"VM"),tsc(U"NM")},.week={7,19971130,7},.first_weekday=1,.first_workday=2},.messages={.yesexpr=tsc(U"^[+1eEsSyY]"),.noexpr=tsc(U"^[-0aAnN]"),.yesstr=tsc(U"ehe"),.nostr=tsc(U"atsa")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"51")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Perú"),.country_ab2=tsc(U"PE"),.country_ab3=tsc(U"PER"),.country_num=604,.country_car=tsc(U"PE"),.lang_name=tsc(U"Awajún"),.lang_ab=tsc(U""),.lang_term=tsc(U""),.lang_lib=tsc(U"agr")},.measurement={.measurement=1}};


}
}

#include"../main.h"