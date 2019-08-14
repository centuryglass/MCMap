#include "Structure.h"
#include <iostream>
#include <map>


// Get's a structure's name value.
std::string structureName(const Structure structure)
{
    switch(structure)
    {
        case Structure::monument:
            return "Monument";
        case Structure::mansion:
            return "Mansion";
        case Structure::swampHut:
            return "Swamp_Hut";
        case Structure::mineshaft:
            return "Mineshaft";
        case Structure::igloo:
            return "Igloo";
        case Structure::stronghold:
            return "Stronghold";
        case Structure::desertPyramid:
            return "Desert_Pyramid";
        case Structure::junglePyramid:
            return "Jungle_Pyramid";
        case Structure::unknown:
            std::cerr << "Invalid structure value.\n";
    };
    return "";
}


// Tries to parse a structure type from a name value.
Structure parseStructure(const std::string name)
{
    static const std::map<std::string, Structure> nameMap =
    {
        { "Monument", Structure::monument },
        { "Mansion", Structure::mansion },
        { "Swamp_Hut", Structure::swampHut },
        { "Mineshaft", Structure::mineshaft },
        { "Igloo", Structure::igloo },
        { "Stronghold", Structure::stronghold },
        { "Desert_Pyramid", Structure::desertPyramid },
        { "Jungle_Pyramid", Structure::junglePyramid }
    };
    const auto iter = nameMap.find(name);
    if (iter == nameMap.end())
    {
        std::cerr << "Unknown structure name " << name << " encountered.\n";
        return Structure::unknown;
    }
    return iter->second;
}


// Gets a color value to represent a Minecraft structure.
png::rgb_pixel getStructureColor(const Structure structure)
{
    static const std::map<Structure, png::rgb_pixel> nameMap =
    {
        { Structure::monument,
                png::rgb_pixel(0x00, 0xe2, 0xaa) },
        { Structure::mansion,
                png::rgb_pixel(0xae, 0x5c, 0x28) },
        { Structure::swampHut,
                png::rgb_pixel(0x05, 0x4c, 0x3e) },
        { Structure::mineshaft ,
                png::rgb_pixel(0x85, 0x06, 0x03) },
        { Structure::igloo,
                png::rgb_pixel(0x0d, 0xe0, 0xec) },
        { Structure::stronghold,
                png::rgb_pixel(0xa3, 0x0c, 0xcc) },
        { Structure::desertPyramid,
                png::rgb_pixel(0xd0, 0xff, 0x00) },
        { Structure::junglePyramid,
                png::rgb_pixel(0x9d, 0x97, 0x09) },
    };
    try
    {
        return nameMap.at(structure);
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Invalid structure type " << structure
                << " encountered.\n";
        return png::rgb_pixel(0, 0, 0);
    }
}
