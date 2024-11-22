#pragma once

/*
W3C standard
File System Access
Draft Community Group Report
https://wicg.github.io/file-system-access/
*/

namespace ufio
{

enum class well_known_directory : ::std::uint_least32_t
{
	desktop,
	documents,
	downloads,
	music,
	pictures,
	videos
};

} // namespace ufio
