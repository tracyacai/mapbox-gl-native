#pragma once

#include <mbgl/style/sources/custom_vector_source.hpp>
#include <mbgl/style/source_impl.hpp>

namespace mbgl {
  namespace style {
    
    class CustomVectorSource::Impl : public Source::Impl {
    public:
      Impl(std::string id, Source&, CustomVectorSourceOptions options, std::function<void(uint8_t, uint32_t, uint32_t)> fetchTile);
      
      void loadDescription(FileSource&) final {}
      
    private:
      CustomVectorSourceOptions options;
      std::function<void(uint8_t, uint32_t, uint32_t)> fetchTile;
      
      uint16_t getTileSize() const;
      Range<uint8_t> getZoomRange() final;
      std::unique_ptr<Tile> createTile(const OverscaledTileID&, const UpdateParameters&) final;
      
    };
    
  } // namespace style
} // namespace mbgl