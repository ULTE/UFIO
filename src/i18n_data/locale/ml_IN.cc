﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3,2};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("ml_IN"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Malayalam language locale for India"),.source=tsc("Free Software Foundation of India, Trivandrum\t\t;\t\tufio"),.address=tsc("https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("ufio"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Malayalam"),.territory=tsc("India"),.revision=tsc("0.1"),.date=tsc("2003-February-01")},.monetary={.int_curr_symbol=tsc("INR "),.currency_symbol=tsc("₹"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={numeric_grouping_storage,2},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,2}},.time={.abday={tsc("ഞാ"),tsc("തി"),tsc("ചൊ"),tsc("ബു"),tsc("വ്യാ"),tsc("വെ"),tsc("ശ")},.day={tsc("ഞായര്‍"),tsc("തിങ്കള്‍"),tsc("ചൊവ്വ"),tsc("ബുധന്‍"),tsc("വ്യാഴം"),tsc("വെള്ളി"),tsc("ശനി")},.abmon={tsc("ജനു"),tsc("ഫെബ്രു"),tsc("മാർ"),tsc("ഏപ്രി"),tsc("മേയ്"),tsc("ജൂൺ"),tsc("ജൂലൈ"),tsc("ഓഗ"),tsc("സെപ്റ്റം"),tsc("ഒക്ടോ"),tsc("നവം"),tsc("ഡിസം")},.mon={tsc("ജനുവരി"),tsc("ഫെബ്രുവരി"),tsc("മാർച്ച്"),tsc("ഏപ്രിൽ"),tsc("മേയ്"),tsc("ജൂൺ"),tsc("ജൂലൈ"),tsc("ഓഗസ്റ്റ്"),tsc("സെപ്റ്റംബർ"),tsc("ഒക്‌ടോബർ"),tsc("നവംബർ"),tsc("ഡിസംബർ")},.d_t_fmt=tsc("%A %d %B %Y %I:%M:%S %p"),.d_fmt=tsc("%-d//%-m//%y"),.t_fmt=tsc("%I:%M:%S %p %Z"),.t_fmt_ampm=tsc("%I:%M:%S %p %Z"),.date_fmt=tsc("%A %d %B %Y %I:%M:%S %p %Z"),.am_pm={tsc("രാവിലെ"),tsc("വൈകു")},.week={7,19971130,1}},.messages={.yesexpr=tsc("^[+1yYഉ]"),.noexpr=tsc("^[-0nNഅ]"),.yesstr=tsc("ഉവ്വ്"),.nostr=tsc("അല്ല")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c ;%a ;%l"),.int_select=tsc("00"),.int_prefix=tsc("91")},.name={.name_fmt=tsc("%p%t%f%t%g"),.name_gen=tsc("ശ്രീ"),.name_miss=tsc("കുമാരി"),.name_mr=tsc("ശ്രീമാനു്"),.name_mrs=tsc("ശ്രീമതി"),.name_ms=tsc("ശ്രീമതി")},.address={.postal_fmt=tsc("%z%c%T%s%b%e%r"),.country_name=tsc("ഇന്ത്യ"),.country_ab2=tsc("IN"),.country_ab3=tsc("IND"),.country_num=356,.country_car=tsc("IND"),.lang_name=tsc("മലയാളം"),.lang_ab=tsc("ml"),.lang_term=tsc("mal"),.lang_lib=tsc("mal")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"ml_IN"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Malayalam language locale for India"),.source=tsc(L"Free Software Foundation of India, Trivandrum\t\t;\t\tufio"),.address=tsc(L"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"ufio"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Malayalam"),.territory=tsc(L"India"),.revision=tsc(L"0.1"),.date=tsc(L"2003-February-01")},.monetary={.int_curr_symbol=tsc(L"INR "),.currency_symbol=tsc(L"₹"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={numeric_grouping_storage,2},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,2}},.time={.abday={tsc(L"ഞാ"),tsc(L"തി"),tsc(L"ചൊ"),tsc(L"ബു"),tsc(L"വ്യാ"),tsc(L"വെ"),tsc(L"ശ")},.day={tsc(L"ഞായര്‍"),tsc(L"തിങ്കള്‍"),tsc(L"ചൊവ്വ"),tsc(L"ബുധന്‍"),tsc(L"വ്യാഴം"),tsc(L"വെള്ളി"),tsc(L"ശനി")},.abmon={tsc(L"ജനു"),tsc(L"ഫെബ്രു"),tsc(L"മാർ"),tsc(L"ഏപ്രി"),tsc(L"മേയ്"),tsc(L"ജൂൺ"),tsc(L"ജൂലൈ"),tsc(L"ഓഗ"),tsc(L"സെപ്റ്റം"),tsc(L"ഒക്ടോ"),tsc(L"നവം"),tsc(L"ഡിസം")},.mon={tsc(L"ജനുവരി"),tsc(L"ഫെബ്രുവരി"),tsc(L"മാർച്ച്"),tsc(L"ഏപ്രിൽ"),tsc(L"മേയ്"),tsc(L"ജൂൺ"),tsc(L"ജൂലൈ"),tsc(L"ഓഗസ്റ്റ്"),tsc(L"സെപ്റ്റംബർ"),tsc(L"ഒക്‌ടോബർ"),tsc(L"നവംബർ"),tsc(L"ഡിസംബർ")},.d_t_fmt=tsc(L"%A %d %B %Y %I:%M:%S %p"),.d_fmt=tsc(L"%-d//%-m//%y"),.t_fmt=tsc(L"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(L"%I:%M:%S %p %Z"),.date_fmt=tsc(L"%A %d %B %Y %I:%M:%S %p %Z"),.am_pm={tsc(L"രാവിലെ"),tsc(L"വൈകു")},.week={7,19971130,1}},.messages={.yesexpr=tsc(L"^[+1yYഉ]"),.noexpr=tsc(L"^[-0nNഅ]"),.yesstr=tsc(L"ഉവ്വ്"),.nostr=tsc(L"അല്ല")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c ;%a ;%l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"91")},.name={.name_fmt=tsc(L"%p%t%f%t%g"),.name_gen=tsc(L"ശ്രീ"),.name_miss=tsc(L"കുമാരി"),.name_mr=tsc(L"ശ്രീമാനു്"),.name_mrs=tsc(L"ശ്രീമതി"),.name_ms=tsc(L"ശ്രീമതി")},.address={.postal_fmt=tsc(L"%z%c%T%s%b%e%r"),.country_name=tsc(L"ഇന്ത്യ"),.country_ab2=tsc(L"IN"),.country_ab3=tsc(L"IND"),.country_num=356,.country_car=tsc(L"IND"),.lang_name=tsc(L"മലയാളം"),.lang_ab=tsc(L"ml"),.lang_term=tsc(L"mal"),.lang_lib=tsc(L"mal")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"ml_IN"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Malayalam language locale for India"),.source=tsc(u8"Free Software Foundation of India, Trivandrum\t\t;\t\tufio"),.address=tsc(u8"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"ufio"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Malayalam"),.territory=tsc(u8"India"),.revision=tsc(u8"0.1"),.date=tsc(u8"2003-February-01")},.monetary={.int_curr_symbol=tsc(u8"INR "),.currency_symbol=tsc(u8"₹"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={numeric_grouping_storage,2},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,2}},.time={.abday={tsc(u8"ഞാ"),tsc(u8"തി"),tsc(u8"ചൊ"),tsc(u8"ബു"),tsc(u8"വ്യാ"),tsc(u8"വെ"),tsc(u8"ശ")},.day={tsc(u8"ഞായര്‍"),tsc(u8"തിങ്കള്‍"),tsc(u8"ചൊവ്വ"),tsc(u8"ബുധന്‍"),tsc(u8"വ്യാഴം"),tsc(u8"വെള്ളി"),tsc(u8"ശനി")},.abmon={tsc(u8"ജനു"),tsc(u8"ഫെബ്രു"),tsc(u8"മാർ"),tsc(u8"ഏപ്രി"),tsc(u8"മേയ്"),tsc(u8"ജൂൺ"),tsc(u8"ജൂലൈ"),tsc(u8"ഓഗ"),tsc(u8"സെപ്റ്റം"),tsc(u8"ഒക്ടോ"),tsc(u8"നവം"),tsc(u8"ഡിസം")},.mon={tsc(u8"ജനുവരി"),tsc(u8"ഫെബ്രുവരി"),tsc(u8"മാർച്ച്"),tsc(u8"ഏപ്രിൽ"),tsc(u8"മേയ്"),tsc(u8"ജൂൺ"),tsc(u8"ജൂലൈ"),tsc(u8"ഓഗസ്റ്റ്"),tsc(u8"സെപ്റ്റംബർ"),tsc(u8"ഒക്‌ടോബർ"),tsc(u8"നവംബർ"),tsc(u8"ഡിസംബർ")},.d_t_fmt=tsc(u8"%A %d %B %Y %I:%M:%S %p"),.d_fmt=tsc(u8"%-d//%-m//%y"),.t_fmt=tsc(u8"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p %Z"),.date_fmt=tsc(u8"%A %d %B %Y %I:%M:%S %p %Z"),.am_pm={tsc(u8"രാവിലെ"),tsc(u8"വൈകു")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u8"^[+1yYഉ]"),.noexpr=tsc(u8"^[-0nNഅ]"),.yesstr=tsc(u8"ഉവ്വ്"),.nostr=tsc(u8"അല്ല")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c ;%a ;%l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"91")},.name={.name_fmt=tsc(u8"%p%t%f%t%g"),.name_gen=tsc(u8"ശ്രീ"),.name_miss=tsc(u8"കുമാരി"),.name_mr=tsc(u8"ശ്രീമാനു്"),.name_mrs=tsc(u8"ശ്രീമതി"),.name_ms=tsc(u8"ശ്രീമതി")},.address={.postal_fmt=tsc(u8"%z%c%T%s%b%e%r"),.country_name=tsc(u8"ഇന്ത്യ"),.country_ab2=tsc(u8"IN"),.country_ab3=tsc(u8"IND"),.country_num=356,.country_car=tsc(u8"IND"),.lang_name=tsc(u8"മലയാളം"),.lang_ab=tsc(u8"ml"),.lang_term=tsc(u8"mal"),.lang_lib=tsc(u8"mal")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"ml_IN"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Malayalam language locale for India"),.source=tsc(u"Free Software Foundation of India, Trivandrum\t\t;\t\tufio"),.address=tsc(u"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"ufio"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Malayalam"),.territory=tsc(u"India"),.revision=tsc(u"0.1"),.date=tsc(u"2003-February-01")},.monetary={.int_curr_symbol=tsc(u"INR "),.currency_symbol=tsc(u"₹"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={numeric_grouping_storage,2},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,2}},.time={.abday={tsc(u"ഞാ"),tsc(u"തി"),tsc(u"ചൊ"),tsc(u"ബു"),tsc(u"വ്യാ"),tsc(u"വെ"),tsc(u"ശ")},.day={tsc(u"ഞായര്‍"),tsc(u"തിങ്കള്‍"),tsc(u"ചൊവ്വ"),tsc(u"ബുധന്‍"),tsc(u"വ്യാഴം"),tsc(u"വെള്ളി"),tsc(u"ശനി")},.abmon={tsc(u"ജനു"),tsc(u"ഫെബ്രു"),tsc(u"മാർ"),tsc(u"ഏപ്രി"),tsc(u"മേയ്"),tsc(u"ജൂൺ"),tsc(u"ജൂലൈ"),tsc(u"ഓഗ"),tsc(u"സെപ്റ്റം"),tsc(u"ഒക്ടോ"),tsc(u"നവം"),tsc(u"ഡിസം")},.mon={tsc(u"ജനുവരി"),tsc(u"ഫെബ്രുവരി"),tsc(u"മാർച്ച്"),tsc(u"ഏപ്രിൽ"),tsc(u"മേയ്"),tsc(u"ജൂൺ"),tsc(u"ജൂലൈ"),tsc(u"ഓഗസ്റ്റ്"),tsc(u"സെപ്റ്റംബർ"),tsc(u"ഒക്‌ടോബർ"),tsc(u"നവംബർ"),tsc(u"ഡിസംബർ")},.d_t_fmt=tsc(u"%A %d %B %Y %I:%M:%S %p"),.d_fmt=tsc(u"%-d//%-m//%y"),.t_fmt=tsc(u"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u"%I:%M:%S %p %Z"),.date_fmt=tsc(u"%A %d %B %Y %I:%M:%S %p %Z"),.am_pm={tsc(u"രാവിലെ"),tsc(u"വൈകു")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u"^[+1yYഉ]"),.noexpr=tsc(u"^[-0nNഅ]"),.yesstr=tsc(u"ഉവ്വ്"),.nostr=tsc(u"അല്ല")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c ;%a ;%l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"91")},.name={.name_fmt=tsc(u"%p%t%f%t%g"),.name_gen=tsc(u"ശ്രീ"),.name_miss=tsc(u"കുമാരി"),.name_mr=tsc(u"ശ്രീമാനു്"),.name_mrs=tsc(u"ശ്രീമതി"),.name_ms=tsc(u"ശ്രീമതി")},.address={.postal_fmt=tsc(u"%z%c%T%s%b%e%r"),.country_name=tsc(u"ഇന്ത്യ"),.country_ab2=tsc(u"IN"),.country_ab3=tsc(u"IND"),.country_num=356,.country_car=tsc(u"IND"),.lang_name=tsc(u"മലയാളം"),.lang_ab=tsc(u"ml"),.lang_term=tsc(u"mal"),.lang_lib=tsc(u"mal")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"ml_IN"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Malayalam language locale for India"),.source=tsc(U"Free Software Foundation of India, Trivandrum\t\t;\t\tufio"),.address=tsc(U"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"ufio"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Malayalam"),.territory=tsc(U"India"),.revision=tsc(U"0.1"),.date=tsc(U"2003-February-01")},.monetary={.int_curr_symbol=tsc(U"INR "),.currency_symbol=tsc(U"₹"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={numeric_grouping_storage,2},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,2}},.time={.abday={tsc(U"ഞാ"),tsc(U"തി"),tsc(U"ചൊ"),tsc(U"ബു"),tsc(U"വ്യാ"),tsc(U"വെ"),tsc(U"ശ")},.day={tsc(U"ഞായര്‍"),tsc(U"തിങ്കള്‍"),tsc(U"ചൊവ്വ"),tsc(U"ബുധന്‍"),tsc(U"വ്യാഴം"),tsc(U"വെള്ളി"),tsc(U"ശനി")},.abmon={tsc(U"ജനു"),tsc(U"ഫെബ്രു"),tsc(U"മാർ"),tsc(U"ഏപ്രി"),tsc(U"മേയ്"),tsc(U"ജൂൺ"),tsc(U"ജൂലൈ"),tsc(U"ഓഗ"),tsc(U"സെപ്റ്റം"),tsc(U"ഒക്ടോ"),tsc(U"നവം"),tsc(U"ഡിസം")},.mon={tsc(U"ജനുവരി"),tsc(U"ഫെബ്രുവരി"),tsc(U"മാർച്ച്"),tsc(U"ഏപ്രിൽ"),tsc(U"മേയ്"),tsc(U"ജൂൺ"),tsc(U"ജൂലൈ"),tsc(U"ഓഗസ്റ്റ്"),tsc(U"സെപ്റ്റംബർ"),tsc(U"ഒക്‌ടോബർ"),tsc(U"നവംബർ"),tsc(U"ഡിസംബർ")},.d_t_fmt=tsc(U"%A %d %B %Y %I:%M:%S %p"),.d_fmt=tsc(U"%-d//%-m//%y"),.t_fmt=tsc(U"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(U"%I:%M:%S %p %Z"),.date_fmt=tsc(U"%A %d %B %Y %I:%M:%S %p %Z"),.am_pm={tsc(U"രാവിലെ"),tsc(U"വൈകു")},.week={7,19971130,1}},.messages={.yesexpr=tsc(U"^[+1yYഉ]"),.noexpr=tsc(U"^[-0nNഅ]"),.yesstr=tsc(U"ഉവ്വ്"),.nostr=tsc(U"അല്ല")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c ;%a ;%l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"91")},.name={.name_fmt=tsc(U"%p%t%f%t%g"),.name_gen=tsc(U"ശ്രീ"),.name_miss=tsc(U"കുമാരി"),.name_mr=tsc(U"ശ്രീമാനു്"),.name_mrs=tsc(U"ശ്രീമതി"),.name_ms=tsc(U"ശ്രീമതി")},.address={.postal_fmt=tsc(U"%z%c%T%s%b%e%r"),.country_name=tsc(U"ഇന്ത്യ"),.country_ab2=tsc(U"IN"),.country_ab3=tsc(U"IND"),.country_num=356,.country_car=tsc(U"IND"),.lang_name=tsc(U"മലയാളം"),.lang_ab=tsc(U"ml"),.lang_term=tsc(U"mal"),.lang_lib=tsc(U"mal")},.measurement={.measurement=1}};


}
}

#include"../main.h"