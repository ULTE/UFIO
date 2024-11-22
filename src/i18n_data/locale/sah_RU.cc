﻿#include"../localedef.h"

namespace ufio_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("sah_RU"),.encoding=tsc(UFIO_LOCALE_ENCODING),.title=tsc("Sakha (Yakut) locale for Russian Federation"),.source=tsc("Valery Timiriliyev\t\t;\t\tufio"),.address=tsc("https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc("Valery Timiriliyev\t\t;\t\tufio"),.email=tsc("timiriliyev@gmail.com;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Sakha"),.territory=tsc("Russian Federation"),.revision=tsc("1.1.0"),.date=tsc("2018-07-06")},.monetary={.int_curr_symbol=tsc("RUB "),.currency_symbol=tsc("₽"),.mon_decimal_point=tsc(","),.mon_thousands_sep=tsc(" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(","),.thousands_sep=tsc(" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("бс"),tsc("бн"),tsc("оп"),tsc("ср"),tsc("чп"),tsc("бт"),tsc("сб")},.day={tsc("баскыһыанньа"),tsc("бэнидиэнньик"),tsc("оптуорунньук"),tsc("сэрэдэ"),tsc("чэппиэр"),tsc("бээтинсэ"),tsc("субуота")},.abmon={tsc("тохс"),tsc("олун"),tsc("кул"),tsc("муус"),tsc("ыам"),tsc("бэс"),tsc("от"),tsc("атыр"),tsc("бал"),tsc("алт"),tsc("сэт"),tsc("ахс")},.mon={tsc("тохсунньу"),tsc("олунньу"),tsc("кулун тутар"),tsc("муус устар"),tsc("ыам ыйын"),tsc("бэс ыйын"),tsc("от ыйын"),tsc("атырдьах ыйын"),tsc("балаҕан ыйын"),tsc("алтынньы"),tsc("сэтинньи"),tsc("ахсынньы")},.d_t_fmt=tsc("%a %Y %b %d %T (%Z)"),.d_fmt=tsc("%Y.%m.%d"),.t_fmt=tsc("%T"),.t_fmt_ampm=tsc(""),.date_fmt=tsc("%a %Y с. %B %e к. %T (%Z)"),.am_pm={tsc(""),tsc("")},.week={7,19971130,1},.first_weekday=2,.first_workday=2},.messages={.yesexpr=tsc("^[+1yYдДэЭ]"),.noexpr=tsc("^[-0nNнНсС]"),.yesstr=tsc("ээх"),.nostr=tsc("суох")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("0~10"),.int_prefix=tsc("7")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Арассыыйа"),.country_ab2=tsc("RU"),.country_ab3=tsc("RUS"),.country_num=643,.country_car=tsc("RUS"),.lang_name=tsc("саха тыла"),.lang_ab=tsc(""),.lang_term=tsc("sah"),.lang_lib=tsc("sah")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"sah_RU"),.encoding=tsc(UFIO_LOCALE_LENCODING),.title=tsc(L"Sakha (Yakut) locale for Russian Federation"),.source=tsc(L"Valery Timiriliyev\t\t;\t\tufio"),.address=tsc(L"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(L"Valery Timiriliyev\t\t;\t\tufio"),.email=tsc(L"timiriliyev@gmail.com;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Sakha"),.territory=tsc(L"Russian Federation"),.revision=tsc(L"1.1.0"),.date=tsc(L"2018-07-06")},.monetary={.int_curr_symbol=tsc(L"RUB "),.currency_symbol=tsc(L"₽"),.mon_decimal_point=tsc(L","),.mon_thousands_sep=tsc(L" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L","),.thousands_sep=tsc(L" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"бс"),tsc(L"бн"),tsc(L"оп"),tsc(L"ср"),tsc(L"чп"),tsc(L"бт"),tsc(L"сб")},.day={tsc(L"баскыһыанньа"),tsc(L"бэнидиэнньик"),tsc(L"оптуорунньук"),tsc(L"сэрэдэ"),tsc(L"чэппиэр"),tsc(L"бээтинсэ"),tsc(L"субуота")},.abmon={tsc(L"тохс"),tsc(L"олун"),tsc(L"кул"),tsc(L"муус"),tsc(L"ыам"),tsc(L"бэс"),tsc(L"от"),tsc(L"атыр"),tsc(L"бал"),tsc(L"алт"),tsc(L"сэт"),tsc(L"ахс")},.mon={tsc(L"тохсунньу"),tsc(L"олунньу"),tsc(L"кулун тутар"),tsc(L"муус устар"),tsc(L"ыам ыйын"),tsc(L"бэс ыйын"),tsc(L"от ыйын"),tsc(L"атырдьах ыйын"),tsc(L"балаҕан ыйын"),tsc(L"алтынньы"),tsc(L"сэтинньи"),tsc(L"ахсынньы")},.d_t_fmt=tsc(L"%a %Y %b %d %T (%Z)"),.d_fmt=tsc(L"%Y.%m.%d"),.t_fmt=tsc(L"%T"),.t_fmt_ampm=tsc(L""),.date_fmt=tsc(L"%a %Y с. %B %e к. %T (%Z)"),.am_pm={tsc(L""),tsc(L"")},.week={7,19971130,1},.first_weekday=2,.first_workday=2},.messages={.yesexpr=tsc(L"^[+1yYдДэЭ]"),.noexpr=tsc(L"^[-0nNнНсС]"),.yesstr=tsc(L"ээх"),.nostr=tsc(L"суох")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"0~10"),.int_prefix=tsc(L"7")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Арассыыйа"),.country_ab2=tsc(L"RU"),.country_ab3=tsc(L"RUS"),.country_num=643,.country_car=tsc(L"RUS"),.lang_name=tsc(L"саха тыла"),.lang_ab=tsc(L""),.lang_term=tsc(L"sah"),.lang_lib=tsc(L"sah")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"sah_RU"),.encoding=tsc(UFIO_LOCALE_u8ENCODING),.title=tsc(u8"Sakha (Yakut) locale for Russian Federation"),.source=tsc(u8"Valery Timiriliyev\t\t;\t\tufio"),.address=tsc(u8"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u8"Valery Timiriliyev\t\t;\t\tufio"),.email=tsc(u8"timiriliyev@gmail.com;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Sakha"),.territory=tsc(u8"Russian Federation"),.revision=tsc(u8"1.1.0"),.date=tsc(u8"2018-07-06")},.monetary={.int_curr_symbol=tsc(u8"RUB "),.currency_symbol=tsc(u8"₽"),.mon_decimal_point=tsc(u8","),.mon_thousands_sep=tsc(u8" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8","),.thousands_sep=tsc(u8" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"бс"),tsc(u8"бн"),tsc(u8"оп"),tsc(u8"ср"),tsc(u8"чп"),tsc(u8"бт"),tsc(u8"сб")},.day={tsc(u8"баскыһыанньа"),tsc(u8"бэнидиэнньик"),tsc(u8"оптуорунньук"),tsc(u8"сэрэдэ"),tsc(u8"чэппиэр"),tsc(u8"бээтинсэ"),tsc(u8"субуота")},.abmon={tsc(u8"тохс"),tsc(u8"олун"),tsc(u8"кул"),tsc(u8"муус"),tsc(u8"ыам"),tsc(u8"бэс"),tsc(u8"от"),tsc(u8"атыр"),tsc(u8"бал"),tsc(u8"алт"),tsc(u8"сэт"),tsc(u8"ахс")},.mon={tsc(u8"тохсунньу"),tsc(u8"олунньу"),tsc(u8"кулун тутар"),tsc(u8"муус устар"),tsc(u8"ыам ыйын"),tsc(u8"бэс ыйын"),tsc(u8"от ыйын"),tsc(u8"атырдьах ыйын"),tsc(u8"балаҕан ыйын"),tsc(u8"алтынньы"),tsc(u8"сэтинньи"),tsc(u8"ахсынньы")},.d_t_fmt=tsc(u8"%a %Y %b %d %T (%Z)"),.d_fmt=tsc(u8"%Y.%m.%d"),.t_fmt=tsc(u8"%T"),.t_fmt_ampm=tsc(u8""),.date_fmt=tsc(u8"%a %Y с. %B %e к. %T (%Z)"),.am_pm={tsc(u8""),tsc(u8"")},.week={7,19971130,1},.first_weekday=2,.first_workday=2},.messages={.yesexpr=tsc(u8"^[+1yYдДэЭ]"),.noexpr=tsc(u8"^[-0nNнНсС]"),.yesstr=tsc(u8"ээх"),.nostr=tsc(u8"суох")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"0~10"),.int_prefix=tsc(u8"7")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Арассыыйа"),.country_ab2=tsc(u8"RU"),.country_ab3=tsc(u8"RUS"),.country_num=643,.country_car=tsc(u8"RUS"),.lang_name=tsc(u8"саха тыла"),.lang_ab=tsc(u8""),.lang_term=tsc(u8"sah"),.lang_lib=tsc(u8"sah")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"sah_RU"),.encoding=tsc(UFIO_LOCALE_uENCODING),.title=tsc(u"Sakha (Yakut) locale for Russian Federation"),.source=tsc(u"Valery Timiriliyev\t\t;\t\tufio"),.address=tsc(u"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(u"Valery Timiriliyev\t\t;\t\tufio"),.email=tsc(u"timiriliyev@gmail.com;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Sakha"),.territory=tsc(u"Russian Federation"),.revision=tsc(u"1.1.0"),.date=tsc(u"2018-07-06")},.monetary={.int_curr_symbol=tsc(u"RUB "),.currency_symbol=tsc(u"₽"),.mon_decimal_point=tsc(u","),.mon_thousands_sep=tsc(u" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u","),.thousands_sep=tsc(u" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"бс"),tsc(u"бн"),tsc(u"оп"),tsc(u"ср"),tsc(u"чп"),tsc(u"бт"),tsc(u"сб")},.day={tsc(u"баскыһыанньа"),tsc(u"бэнидиэнньик"),tsc(u"оптуорунньук"),tsc(u"сэрэдэ"),tsc(u"чэппиэр"),tsc(u"бээтинсэ"),tsc(u"субуота")},.abmon={tsc(u"тохс"),tsc(u"олун"),tsc(u"кул"),tsc(u"муус"),tsc(u"ыам"),tsc(u"бэс"),tsc(u"от"),tsc(u"атыр"),tsc(u"бал"),tsc(u"алт"),tsc(u"сэт"),tsc(u"ахс")},.mon={tsc(u"тохсунньу"),tsc(u"олунньу"),tsc(u"кулун тутар"),tsc(u"муус устар"),tsc(u"ыам ыйын"),tsc(u"бэс ыйын"),tsc(u"от ыйын"),tsc(u"атырдьах ыйын"),tsc(u"балаҕан ыйын"),tsc(u"алтынньы"),tsc(u"сэтинньи"),tsc(u"ахсынньы")},.d_t_fmt=tsc(u"%a %Y %b %d %T (%Z)"),.d_fmt=tsc(u"%Y.%m.%d"),.t_fmt=tsc(u"%T"),.t_fmt_ampm=tsc(u""),.date_fmt=tsc(u"%a %Y с. %B %e к. %T (%Z)"),.am_pm={tsc(u""),tsc(u"")},.week={7,19971130,1},.first_weekday=2,.first_workday=2},.messages={.yesexpr=tsc(u"^[+1yYдДэЭ]"),.noexpr=tsc(u"^[-0nNнНсС]"),.yesstr=tsc(u"ээх"),.nostr=tsc(u"суох")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"0~10"),.int_prefix=tsc(u"7")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Арассыыйа"),.country_ab2=tsc(u"RU"),.country_ab3=tsc(u"RUS"),.country_num=643,.country_car=tsc(u"RUS"),.lang_name=tsc(u"саха тыла"),.lang_ab=tsc(u""),.lang_term=tsc(u"sah"),.lang_lib=tsc(u"sah")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"sah_RU"),.encoding=tsc(UFIO_LOCALE_UENCODING),.title=tsc(U"Sakha (Yakut) locale for Russian Federation"),.source=tsc(U"Valery Timiriliyev\t\t;\t\tufio"),.address=tsc(U"https://gitee.com/qabeowjbtkwb/ufio\t\t;\t\thttps://github.com/cppfastio/ufio"),.contact=tsc(U"Valery Timiriliyev\t\t;\t\tufio"),.email=tsc(U"timiriliyev@gmail.com;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Sakha"),.territory=tsc(U"Russian Federation"),.revision=tsc(U"1.1.0"),.date=tsc(U"2018-07-06")},.monetary={.int_curr_symbol=tsc(U"RUB "),.currency_symbol=tsc(U"₽"),.mon_decimal_point=tsc(U","),.mon_thousands_sep=tsc(U" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U","),.thousands_sep=tsc(U" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"бс"),tsc(U"бн"),tsc(U"оп"),tsc(U"ср"),tsc(U"чп"),tsc(U"бт"),tsc(U"сб")},.day={tsc(U"баскыһыанньа"),tsc(U"бэнидиэнньик"),tsc(U"оптуорунньук"),tsc(U"сэрэдэ"),tsc(U"чэппиэр"),tsc(U"бээтинсэ"),tsc(U"субуота")},.abmon={tsc(U"тохс"),tsc(U"олун"),tsc(U"кул"),tsc(U"муус"),tsc(U"ыам"),tsc(U"бэс"),tsc(U"от"),tsc(U"атыр"),tsc(U"бал"),tsc(U"алт"),tsc(U"сэт"),tsc(U"ахс")},.mon={tsc(U"тохсунньу"),tsc(U"олунньу"),tsc(U"кулун тутар"),tsc(U"муус устар"),tsc(U"ыам ыйын"),tsc(U"бэс ыйын"),tsc(U"от ыйын"),tsc(U"атырдьах ыйын"),tsc(U"балаҕан ыйын"),tsc(U"алтынньы"),tsc(U"сэтинньи"),tsc(U"ахсынньы")},.d_t_fmt=tsc(U"%a %Y %b %d %T (%Z)"),.d_fmt=tsc(U"%Y.%m.%d"),.t_fmt=tsc(U"%T"),.t_fmt_ampm=tsc(U""),.date_fmt=tsc(U"%a %Y с. %B %e к. %T (%Z)"),.am_pm={tsc(U""),tsc(U"")},.week={7,19971130,1},.first_weekday=2,.first_workday=2},.messages={.yesexpr=tsc(U"^[+1yYдДэЭ]"),.noexpr=tsc(U"^[-0nNнНсС]"),.yesstr=tsc(U"ээх"),.nostr=tsc(U"суох")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"0~10"),.int_prefix=tsc(U"7")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Арассыыйа"),.country_ab2=tsc(U"RU"),.country_ab3=tsc(U"RUS"),.country_num=643,.country_car=tsc(U"RUS"),.lang_name=tsc(U"саха тыла"),.lang_ab=tsc(U""),.lang_term=tsc(U"sah"),.lang_lib=tsc(U"sah")},.measurement={.measurement=1}};


}
}

#include"../main.h"