﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("ik_CA"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Inupiaq locale for Canada"),.source=tsc("ufio"),.address=tsc("https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("pablo@mandriva.com;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Inupiaq"),.territory=tsc("Canada"),.revision=tsc("0.2"),.date=tsc("2004-08-01")},.monetary={.int_curr_symbol=tsc("CAD "),.currency_symbol=tsc("$"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("Min"),tsc("Sav"),tsc("Ila"),tsc("Qit"),tsc("Sis"),tsc("Tal"),tsc("Maq")},.day={tsc("Minġuiqsioiq"),tsc("Savałłiq"),tsc("Ilaqtchiioiq"),tsc("Qitchiioiq"),tsc("Sisamiioiq"),tsc("Tallimmiioiq"),tsc("Maqinġuoiq")},.abmon={tsc("Sñt"),tsc("Sñs"),tsc("Pan"),tsc("Qil"),tsc("Sup"),tsc("Iġñ"),tsc("Itc"),tsc("Tiñ"),tsc("Ami"),tsc("Sik"),tsc("Nip"),tsc("Siq")},.mon={tsc("Siqiññaatchiaq"),tsc("Siqiññaasrugruk"),tsc("Paniqsiqsiivik"),tsc("Qilġich Tatqiat"),tsc("Suppivik"),tsc("Iġñivik"),tsc("Itchavik"),tsc("Tiññivik"),tsc("Amiġaiqsivik"),tsc("Sikkuvik"),tsc("Nippivik"),tsc("Siqiñġiḷaq")},.d_t_fmt=tsc("%a %d %b %Y %r"),.d_fmt=tsc("%d//%m//%y"),.t_fmt=tsc("%r"),.t_fmt_ampm=tsc("%I:%M:%S %p"),.date_fmt=tsc("%a %d %b %Y %r %Z"),.am_pm={tsc("AM"),tsc("PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc("^[+1yYiIaA]"),.noexpr=tsc("^[-0nNqQ]"),.yesstr=tsc("aa"),.nostr=tsc("qañaa")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("011"),.int_prefix=tsc("1")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Kanada"),.country_ab2=tsc("CA"),.country_ab3=tsc("CAN"),.country_num=124,.country_car=tsc("CDN"),.lang_name=tsc("Iñupiatun"),.lang_ab=tsc("ik"),.lang_term=tsc("ipk"),.lang_lib=tsc("ipk")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"ik_CA"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Inupiaq locale for Canada"),.source=tsc(L"ufio"),.address=tsc(L"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"pablo@mandriva.com;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Inupiaq"),.territory=tsc(L"Canada"),.revision=tsc(L"0.2"),.date=tsc(L"2004-08-01")},.monetary={.int_curr_symbol=tsc(L"CAD "),.currency_symbol=tsc(L"$"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"Min"),tsc(L"Sav"),tsc(L"Ila"),tsc(L"Qit"),tsc(L"Sis"),tsc(L"Tal"),tsc(L"Maq")},.day={tsc(L"Minġuiqsioiq"),tsc(L"Savałłiq"),tsc(L"Ilaqtchiioiq"),tsc(L"Qitchiioiq"),tsc(L"Sisamiioiq"),tsc(L"Tallimmiioiq"),tsc(L"Maqinġuoiq")},.abmon={tsc(L"Sñt"),tsc(L"Sñs"),tsc(L"Pan"),tsc(L"Qil"),tsc(L"Sup"),tsc(L"Iġñ"),tsc(L"Itc"),tsc(L"Tiñ"),tsc(L"Ami"),tsc(L"Sik"),tsc(L"Nip"),tsc(L"Siq")},.mon={tsc(L"Siqiññaatchiaq"),tsc(L"Siqiññaasrugruk"),tsc(L"Paniqsiqsiivik"),tsc(L"Qilġich Tatqiat"),tsc(L"Suppivik"),tsc(L"Iġñivik"),tsc(L"Itchavik"),tsc(L"Tiññivik"),tsc(L"Amiġaiqsivik"),tsc(L"Sikkuvik"),tsc(L"Nippivik"),tsc(L"Siqiñġiḷaq")},.d_t_fmt=tsc(L"%a %d %b %Y %r"),.d_fmt=tsc(L"%d//%m//%y"),.t_fmt=tsc(L"%r"),.t_fmt_ampm=tsc(L"%I:%M:%S %p"),.date_fmt=tsc(L"%a %d %b %Y %r %Z"),.am_pm={tsc(L"AM"),tsc(L"PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc(L"^[+1yYiIaA]"),.noexpr=tsc(L"^[-0nNqQ]"),.yesstr=tsc(L"aa"),.nostr=tsc(L"qañaa")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"011"),.int_prefix=tsc(L"1")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Kanada"),.country_ab2=tsc(L"CA"),.country_ab3=tsc(L"CAN"),.country_num=124,.country_car=tsc(L"CDN"),.lang_name=tsc(L"Iñupiatun"),.lang_ab=tsc(L"ik"),.lang_term=tsc(L"ipk"),.lang_lib=tsc(L"ipk")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"ik_CA"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Inupiaq locale for Canada"),.source=tsc(u8"ufio"),.address=tsc(u8"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"pablo@mandriva.com;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Inupiaq"),.territory=tsc(u8"Canada"),.revision=tsc(u8"0.2"),.date=tsc(u8"2004-08-01")},.monetary={.int_curr_symbol=tsc(u8"CAD "),.currency_symbol=tsc(u8"$"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"Min"),tsc(u8"Sav"),tsc(u8"Ila"),tsc(u8"Qit"),tsc(u8"Sis"),tsc(u8"Tal"),tsc(u8"Maq")},.day={tsc(u8"Minġuiqsioiq"),tsc(u8"Savałłiq"),tsc(u8"Ilaqtchiioiq"),tsc(u8"Qitchiioiq"),tsc(u8"Sisamiioiq"),tsc(u8"Tallimmiioiq"),tsc(u8"Maqinġuoiq")},.abmon={tsc(u8"Sñt"),tsc(u8"Sñs"),tsc(u8"Pan"),tsc(u8"Qil"),tsc(u8"Sup"),tsc(u8"Iġñ"),tsc(u8"Itc"),tsc(u8"Tiñ"),tsc(u8"Ami"),tsc(u8"Sik"),tsc(u8"Nip"),tsc(u8"Siq")},.mon={tsc(u8"Siqiññaatchiaq"),tsc(u8"Siqiññaasrugruk"),tsc(u8"Paniqsiqsiivik"),tsc(u8"Qilġich Tatqiat"),tsc(u8"Suppivik"),tsc(u8"Iġñivik"),tsc(u8"Itchavik"),tsc(u8"Tiññivik"),tsc(u8"Amiġaiqsivik"),tsc(u8"Sikkuvik"),tsc(u8"Nippivik"),tsc(u8"Siqiñġiḷaq")},.d_t_fmt=tsc(u8"%a %d %b %Y %r"),.d_fmt=tsc(u8"%d//%m//%y"),.t_fmt=tsc(u8"%r"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p"),.date_fmt=tsc(u8"%a %d %b %Y %r %Z"),.am_pm={tsc(u8"AM"),tsc(u8"PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u8"^[+1yYiIaA]"),.noexpr=tsc(u8"^[-0nNqQ]"),.yesstr=tsc(u8"aa"),.nostr=tsc(u8"qañaa")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"011"),.int_prefix=tsc(u8"1")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Kanada"),.country_ab2=tsc(u8"CA"),.country_ab3=tsc(u8"CAN"),.country_num=124,.country_car=tsc(u8"CDN"),.lang_name=tsc(u8"Iñupiatun"),.lang_ab=tsc(u8"ik"),.lang_term=tsc(u8"ipk"),.lang_lib=tsc(u8"ipk")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"ik_CA"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Inupiaq locale for Canada"),.source=tsc(u"ufio"),.address=tsc(u"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"pablo@mandriva.com;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Inupiaq"),.territory=tsc(u"Canada"),.revision=tsc(u"0.2"),.date=tsc(u"2004-08-01")},.monetary={.int_curr_symbol=tsc(u"CAD "),.currency_symbol=tsc(u"$"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"Min"),tsc(u"Sav"),tsc(u"Ila"),tsc(u"Qit"),tsc(u"Sis"),tsc(u"Tal"),tsc(u"Maq")},.day={tsc(u"Minġuiqsioiq"),tsc(u"Savałłiq"),tsc(u"Ilaqtchiioiq"),tsc(u"Qitchiioiq"),tsc(u"Sisamiioiq"),tsc(u"Tallimmiioiq"),tsc(u"Maqinġuoiq")},.abmon={tsc(u"Sñt"),tsc(u"Sñs"),tsc(u"Pan"),tsc(u"Qil"),tsc(u"Sup"),tsc(u"Iġñ"),tsc(u"Itc"),tsc(u"Tiñ"),tsc(u"Ami"),tsc(u"Sik"),tsc(u"Nip"),tsc(u"Siq")},.mon={tsc(u"Siqiññaatchiaq"),tsc(u"Siqiññaasrugruk"),tsc(u"Paniqsiqsiivik"),tsc(u"Qilġich Tatqiat"),tsc(u"Suppivik"),tsc(u"Iġñivik"),tsc(u"Itchavik"),tsc(u"Tiññivik"),tsc(u"Amiġaiqsivik"),tsc(u"Sikkuvik"),tsc(u"Nippivik"),tsc(u"Siqiñġiḷaq")},.d_t_fmt=tsc(u"%a %d %b %Y %r"),.d_fmt=tsc(u"%d//%m//%y"),.t_fmt=tsc(u"%r"),.t_fmt_ampm=tsc(u"%I:%M:%S %p"),.date_fmt=tsc(u"%a %d %b %Y %r %Z"),.am_pm={tsc(u"AM"),tsc(u"PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u"^[+1yYiIaA]"),.noexpr=tsc(u"^[-0nNqQ]"),.yesstr=tsc(u"aa"),.nostr=tsc(u"qañaa")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"011"),.int_prefix=tsc(u"1")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Kanada"),.country_ab2=tsc(u"CA"),.country_ab3=tsc(u"CAN"),.country_num=124,.country_car=tsc(u"CDN"),.lang_name=tsc(u"Iñupiatun"),.lang_ab=tsc(u"ik"),.lang_term=tsc(u"ipk"),.lang_lib=tsc(u"ipk")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"ik_CA"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Inupiaq locale for Canada"),.source=tsc(U"ufio"),.address=tsc(U"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"pablo@mandriva.com;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Inupiaq"),.territory=tsc(U"Canada"),.revision=tsc(U"0.2"),.date=tsc(U"2004-08-01")},.monetary={.int_curr_symbol=tsc(U"CAD "),.currency_symbol=tsc(U"$"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"Min"),tsc(U"Sav"),tsc(U"Ila"),tsc(U"Qit"),tsc(U"Sis"),tsc(U"Tal"),tsc(U"Maq")},.day={tsc(U"Minġuiqsioiq"),tsc(U"Savałłiq"),tsc(U"Ilaqtchiioiq"),tsc(U"Qitchiioiq"),tsc(U"Sisamiioiq"),tsc(U"Tallimmiioiq"),tsc(U"Maqinġuoiq")},.abmon={tsc(U"Sñt"),tsc(U"Sñs"),tsc(U"Pan"),tsc(U"Qil"),tsc(U"Sup"),tsc(U"Iġñ"),tsc(U"Itc"),tsc(U"Tiñ"),tsc(U"Ami"),tsc(U"Sik"),tsc(U"Nip"),tsc(U"Siq")},.mon={tsc(U"Siqiññaatchiaq"),tsc(U"Siqiññaasrugruk"),tsc(U"Paniqsiqsiivik"),tsc(U"Qilġich Tatqiat"),tsc(U"Suppivik"),tsc(U"Iġñivik"),tsc(U"Itchavik"),tsc(U"Tiññivik"),tsc(U"Amiġaiqsivik"),tsc(U"Sikkuvik"),tsc(U"Nippivik"),tsc(U"Siqiñġiḷaq")},.d_t_fmt=tsc(U"%a %d %b %Y %r"),.d_fmt=tsc(U"%d//%m//%y"),.t_fmt=tsc(U"%r"),.t_fmt_ampm=tsc(U"%I:%M:%S %p"),.date_fmt=tsc(U"%a %d %b %Y %r %Z"),.am_pm={tsc(U"AM"),tsc(U"PM")},.week={7,19971130,1}},.messages={.yesexpr=tsc(U"^[+1yYiIaA]"),.noexpr=tsc(U"^[-0nNqQ]"),.yesstr=tsc(U"aa"),.nostr=tsc(U"qañaa")},.paper={.width=216,.height=279},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"011"),.int_prefix=tsc(U"1")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Kanada"),.country_ab2=tsc(U"CA"),.country_ab3=tsc(U"CAN"),.country_num=124,.country_car=tsc(U"CDN"),.lang_name=tsc(U"Iñupiatun"),.lang_ab=tsc(U"ik"),.lang_term=tsc(U"ipk"),.lang_lib=tsc(U"ipk")},.measurement={.measurement=1}};


}
}

#include"../main.h"