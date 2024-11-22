#include <ufio.h>
#include <ufio_driver/pulseaudio.h>
#include <memory>

int main()
{
	/*
	Referenced from
	https://www.freedesktop.org/software/pulseaudio/doxygen/simple.html
	*/
	pa_sample_spec ss{.format = PA_SAMPLE_S16NE, .rate = 44100, .channels = 2};
	::ufio::pulseaudio_simple_file psf(::ufio::native_interface, nullptr, "fooapp", PA_STREAM_PLAYBACK, nullptr,
										  "MUSIC", std::addressof(ss), nullptr, nullptr);
	for (;;) // for loop so we can hear hello world
	{
		::ufio::io::print(psf, "Hello World\n");
	}
}
/*
need to link -lpulse-simple
*/
