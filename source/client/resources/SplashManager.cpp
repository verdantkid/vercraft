#include <sstream>
#include "SplashManager.hpp"
#include "Resource.hpp"
#include "common/Util.hpp"

SplashManager* SplashManager::instance = nullptr;

void SplashManager::init(const std::string& user)
{
    m_splashes.clear();
    std::string file;
    if (!Resource::load("title/splashes.txt", file)) return;
    std::istringstream stream(file);
    std::string line;

    while (std::getline(stream, line))
    {
        if (line.empty())
            continue;

        if (line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        if (line.compare(0, 2, "//") == 0)
            continue;

        m_splashes.push_back(line);
    }

#if MCE_GFX_API_OGL
#ifdef USE_GLES
    m_splashes.push_back("awwwwww, bad pc?");
#else
    m_splashes.push_back("VerdantKid was here");
#endif
#elif MCE_GFX_API_D3D11
    m_splashes.push_back("who the fuck is using windows to play this :sob:");
#elif MCE_GFX_API_D3D9
    m_splashes.push_back("I am gayyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy.");
#endif

    m_isYouSplash = Util::format("%s IS YOU", user.c_str());
}

const std::string& SplashManager::getSplash()
{
    //Add splashes for holidays?
    if (m_random.nextInt(m_splashes.size()) == 42) return m_isYouSplash;

    return m_splashes[m_random.nextInt(m_splashes.size())];
}
