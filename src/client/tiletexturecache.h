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

#ifndef TILE_TEXTURE_CACHE_H
#define TILE_TEXTURE_CACHE_H

#include "declarations.h"
#include "item.h"
#include <framework/core/declarations.h>
#include <framework/graphics/texture.h>
#include <framework/stdext/types.h>

class TileTextureCache : public stdext::shared_object
{
public:
    TileTextureCache() {};
    TileTextureCachePtr& getCache(const ItemPtr& item);

    const TexturePtr& getTexture() { return m_texture; }

private:
    TileTextureCachePtr m_parent;
    TexturePtr m_texture;
    std::unordered_map<uint32, std::vector<TileTextureCachePtr>> m_children;
};

extern TileTextureCache g_tileTextureCache;

#endif
