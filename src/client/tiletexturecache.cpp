/*
 * Copyright (c) 2010-2020 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "tiletexturecache.h"

TileTextureCache g_tileTextureCache;

TileTextureCachePtr TileTextureCache::getCache(const ItemPtr& item)
{
    const int key = item->getId();
    const auto& point = m_children.find(key);
    const int currentAnimationPhase = item->getCurrentAnimationPhase(false);

    if(point != m_children.end()) {
        return point->second[currentAnimationPhase];
    }

    const auto& thingType = item->getThingType();
    const auto size = thingType->getAnimationPhases();

    std::vector<TileTextureCachePtr> list;
    list.resize(size);

    for(size_t i = -1; ++i < size;) {
        TileTextureCachePtr ttc = TileTextureCachePtr(new TileTextureCache);
        ttc->m_parent = this;
        ttc->m_texture = thingType->generateTexture(item->getCurrentAnimationPhase(false));
        if(this->m_texture)
            ttc->m_texture->uploadPixels(this->m_texture->getImage());

        list[0] = ttc;
    }

    m_children.insert(std::make_pair(key, list));

    return list[currentAnimationPhase];
}