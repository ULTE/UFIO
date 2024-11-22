#pragma once

namespace ufio::details
{

enum class posix_api_22
{
	renameat,
	linkat
};
enum class posix_api_12
{
	symlinkat
};
enum class posix_api_1x
{
	faccessat,
	utimensat,
	fchmodat,
	fchownat,
	fstatat,
	mkdirat,
	mknodat,
	unlinkat
};

} // namespace ufio::details
