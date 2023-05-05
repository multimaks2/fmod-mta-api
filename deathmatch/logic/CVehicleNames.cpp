/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *               (Shared logic for modifications)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/shared_logic/CVehicleNames.cpp
 *  PURPOSE:     Vehicle names class
 *
 *****************************************************************************/

#include <StdInc.h>

using namespace std;

const char* const szVehicleNameEmpty = "";

struct SVehicleName
{
    const char* szName;
    const char* szName_replaced;            // Compatability
};

#define MIN_V_SIZE     18593
#define MAX_V_SIZE     18665
#define VEHNUMBER_SIZE 276

struct CLTABLEVEHINFO
{
    unsigned long ID;
    const char*   Vehicle_Name;
};

static const SFixedArray<CLTABLEVEHINFO, VEHNUMBER_SIZE> CustomVehicleTablaInfo = {{
    {400, "Landstalker"},
    {401, "Bravura"},
    {402, "Buffalo"},
    {403, "Linerunner"},
    {404, "Perennial"},
    {405, "Sentinel"},
    {406, "Dumper"},
    {407, "Fire Truck"},
    {408, "Trashmaster"},
    {409, "Stretch"},
    {410, "Manana"},
    {411, "Infernus"},
    {412, "Voodoo"},
    {413, "Pony"},
    {414, "Mule"},
    {415, "Cheetah"},
    {416, "Ambulance"},
    {417, "Leviathan"},
    {418, "Moonbeam"},
    {419, "Esperanto"},
    {420, "Taxi"},
    {421, "Washington"},
    {422, "Bobcat"},
    {423, "Mr. Whoopee"},
    {424, "BF Injection"},
    {425, "Hunter"},
    {426, "Premier"},
    {427, "Enforcer"},
    {428, "Securicar"},
    {429, "Banshee"},
    {430, "Predator"},
    {431, "Bus"},
    {432, "Rhino"},
    {433, "Barracks"},
    {434, "Hotknife"},
    {435, "Trailer 1"},
    {436, "Previon"},
    {437, "Coach"},
    {438, "Cabbie"},
    {439, "Stallion"},
    {440, "Rumpo"},
    {441, "RC Bandit"},
    {442, "Romero"},
    {443, "Packer"},
    {444, "Monster 1"},
    {445, "Admiral"},
    {446, "Squalo"},
    {447, "Seasparrow"},
    {448, "Pizzaboy"},
    {449, "Tram"},
    {450, "Trailer 2"},
    {451, "Turismo"},
    {452, "Speeder"},
    {453, "Reefer"},
    {454, "Tropic"},
    {455, "Flatbed"},
    {456, "Yankee"},
    {457, "Caddy"},
    {458, "Solair"},
    {459, "Berkley's RC Van"},
    {460, "Skimmer"},
    {461, "PCJ-600"},
    {462, "Faggio"},
    {463, "Freeway"},
    {464, "RC Baron"},
    {465, "RC Raider"},
    {466, "Glendale"},
    {467, "Oceanic"},
    {468, "Sanchez"},
    {469, "Sparrow"},
    {470, "Patriot"},
    {471, "Quadbike"},
    {472, "Coastguard"},
    {473, "Dinghy"},
    {474, "Hermes"},
    {475, "Sabre"},
    {476, "Rustler"},
    {477, "ZR-350"},
    {478, "Walton"},
    {479, "Regina"},
    {480, "Comet"},
    {481, "BMX"},
    {482, "Burrito"},
    {483, "Camper"},
    {484, "Marquis"},
    {485, "Baggage"},
    {486, "Dozer"},
    {487, "Maverick"},
    {488, "News Chopper"},
    {489, "Rancher"},
    {490, "FBI Rancher"},
    {491, "Virgo"},
    {492, "Greenwood"},
    {493, "Jetmax"},
    {494, "Hotring Racer"},
    {495, "Sandking"},
    {496, "Blista Compact"},
    {497, "Police Maverick"},
    {498, "Boxville"},
    {499, "Benson"},
    {500, "Mesa"},
    {501, "RC Goblin"},
    {502, "Hotring Racer 3"},
    {503, "Hotring Racer 2"},
    {504, "Bloodring Banger"},
    {505, "Rancher Lure"},
    {506, "Super GT"},
    {507, "Elegant"},
    {508, "Journey"},
    {509, "Bike"},
    {510, "Mountain Bike"},
    {511, "Beagle"},
    {512, "Cropduster"},
    {513, "Stuntplane"},
    {514, "Tanker"},
    {515, "Roadtrain"},
    {516, "Nebula"},
    {517, "Majestic"},
    {518, "Buccaneer"},
    {519, "Shamal"},
    {520, "Hydra"},
    {521, "FCR-900"},
    {522, "NRG-500"},
    {523, "HPV1000"},
    {524, "Cement Truck"},
    {525, "Towtruck"},
    {526, "Fortune"},
    {527, "Cadrona"},
    {528, "FBI Truck"},
    {529, "Willard"},
    {530, "Forklift"},
    {531, "Tractor"},
    {532, "Combine Harvester"},
    {533, "Feltzer"},
    {534, "Remington"},
    {535, "Slamvan"},
    {536, "Blade"},
    {537, "Freight"},
    {538, "Streak"},
    {539, "Vortex"},
    {540, "Vincent"},
    {541, "Bullet"},
    {542, "Clover"},
    {543, "Sadler"},
    {544, "Fire Truck Ladder"},
    {545, "Hustler"},
    {546, "Intruder"},
    {547, "Primo"},
    {548, "Cargobob"},
    {549, "Tampa"},
    {550, "Sunrise"},
    {551, "Merit"},
    {552, "Utility Van"},
    {553, "Nevada"},
    {554, "Yosemite"},
    {555, "Windsor"},
    {556, "Monster 2"},
    {557, "Monster 3"},
    {558, "Uranus"},
    {559, "Jester"},
    {560, "Sultan"},
    {561, "Stratum"},
    {562, "Elegy"},
    {563, "Raindance"},
    {564, "RC Tiger"},
    {565, "Flash"},
    {566, "Tahoma"},
    {567, "Savanna"},
    {568, "Bandito"},
    {569, "Freight Train Flatbed"},
    {570, "Streak Train Trailer"},
    {571, "Kart"},
    {572, "Mower"},
    {573, "Dune"},
    {574, "Sweeper"},
    {575, "Broadway"},
    {576, "Tornado"},
    {577, "AT-400"},
    {578, "DFT-30"},
    {579, "Huntley"},
    {580, "Stafford"},
    {581, "BF-400"},
    {582, "Newsvan"},
    {583, "Tug"},
    {584, "Trailer (Tanker Commando)"},
    {585, "Emperor"},
    {586, "Wayfarer"},
    {587, "Euros"},
    {588, "Hotdog"},
    {589, "Club"},
    {590, "Box Freight"},
    {591, "Trailer 3"},
    {592, "Andromada"},
    {593, "Dodo"},
    {594, "RC Cam"},
    {595, "Launch"},
    {596, "Police LS"},
    {597, "Police SF"},
    {598, "Police LV"},
    {599, "Police Ranger"},
    {600, "Picador"},
    {601, "S.W.A.T."},
    {602, "Alpha"},
    {603, "Phoenix"},
    {604, "Glendale Damaged"},
    {605, "Sadler Damaged"},
    {606, "Baggage Trailer (covered)"},
    {607, "Baggage Trailer (Uncovered)"},
    {608, "Trailer (Stairs)"},
    {609, "Boxville Mission"},
    {610, "Farm Trailer"},
    {611, "Street Clean Trailer"},
    {18593, "file_18593"},
    {18594, "file_18594"},
    {18595, "file_18595"},
    {18596, "file_18596"},
    {18597, "file_18597"},
    {18598, "file_18598"},
    {18599, "file_18599"},
    {18600, "file_18600"},
    {18601, "file_18601"},
    {18602, "file_18602"},
    {18603, "file_18603"},
    {18613, "file_18613"},
    {18614, "file_18614"},
    {18615, "file_18615"},
    {18616, "file_18616"},
    {18617, "file_18617"},
    {18618, "file_18618"},
    {18619, "file_18619"},
    {18620, "file_18620"},
    {18621, "file_18621"},
    {18622, "file_18622"},
    {18623, "file_18623"},
    {18624, "file_18624"},
    {18625, "file_18625"},
    {18626, "file_18626"},
    {18627, "file_18627"},
    {18628, "file_18628"},
    {18629, "file_18629"},
    {18630, "file_18630"},
    {18631, "file_18631"},
    {18632, "file_18632"},
    {18633, "file_18633"},
    {18634, "file_18634"},
    {18635, "file_18635"},
    {18636, "file_18636"},
    {18637, "file_18637"},
    {18638, "file_18638"},
    {18639, "file_18639"},
    {18640, "file_18640"},
    {18641, "file_18641"},
    {18642, "file_18642"},
    {18643, "file_18643"},
    {18644, "file_18644"},
    {18645, "file_18645"},
    {18646, "file_18646"},
    {18647, "file_18647"},
    {18648, "file_18648"},
    {18649, "file_18649"},
    {18650, "file_18650"},
    {18651, "file_18651"},
    {18652, "file_18652"},
    {18653, "file_18653"},
    {18654, "file_18654"},
    {18655, "file_18655"},
    {18656, "file_18656"},
    {18657, "file_18657"},
    {18658, "file_18658"},
    {18659, "file_18659"},
    {18660, "file_18660"},
    {18661, "file_18661"},
    {18662, "file_18662"},
    {18663, "file_18663"},
    {18664, "file_18664"},
    {18665, "file_18665"},
}};

static const SFixedArray<SVehicleName, 10> VehicleTypes = {
    {{"Automobile"}, {"Plane"}, {"Bike"}, {"Helicopter"}, {"Boat"}, {"Train"}, {"Trailer"}, {"BMX"}, {"Monster Truck"}, {"Quad"}}};

static const SFixedArray<unsigned char, 212> ucVehicleTypes = {
    0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0,
    0, 8, 0, 4, 3, 2, 5, 6, 0, 4, 4, 4, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 3, 0, 0, 2, 3, 0, 9, 4, 4, 0, 0, 1, 0, 0, 0, 0, 7, 0, 0, 4, 0,
    0, 3, 3, 0, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 7, 7, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 8, 8, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 5, 5, 0,
    0, 8, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 6, 0, 2, 0, 0, 0, 5, 6, 1, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 0, 6, 6};

bool CVehicleNames::IsValidModel(unsigned long ulModel)
{
    for (unsigned int i = 0; i < NUMELMS(CustomVehicleTablaInfo); i++)
    {
        if (CustomVehicleTablaInfo[i].ID == ulModel)
        {
            return true;
        }
    }
    return false;
}

bool CVehicleNames::IsModelTrailer(unsigned long ulModel)
{
    // IsValidModel excludes trailers, so we need the ability to check separately if it is a trailer
    return (ulModel == 435 || ulModel == 450 || ulModel == 591 || ulModel == 606 || ulModel == 607 || ulModel == 584 || ulModel == 608 || ulModel == 610 ||
            ulModel == 611);
}

const char* CVehicleNames::GetVehicleName(unsigned long ulModel)
{
    for (unsigned int i = 0; i < NUMELMS(CustomVehicleTablaInfo); i++)
    {
        if (CustomVehicleTablaInfo[i].ID == ulModel)
        {
            return CustomVehicleTablaInfo[i].Vehicle_Name;
        }
    }
    return szVehicleNameEmpty;
}

unsigned int CVehicleNames::GetVehicleModel(const char* szName)
{
    // If the specified string was empty, return 0
    if (szName[0] == 0)
        return 0;

    // Look for it in our table
    for (unsigned int i = 0; i < NUMELMS(CustomVehicleTablaInfo); i++)
    {
        if (stricmp(szName, CustomVehicleTablaInfo[i].Vehicle_Name) == 0 ||
            (CustomVehicleTablaInfo[i].Vehicle_Name && stricmp(szName, CustomVehicleTablaInfo[i].Vehicle_Name) == 0))
        {
            return CustomVehicleTablaInfo[i].ID;
        }
    }
    return 0;
}

const char* CVehicleNames::GetVehicleTypeName(unsigned long ulModel)
{
    if (ulModel >= MIN_V_SIZE && ulModel <= MAX_V_SIZE)
    {
        return "Automobile";
    }
    if ((IsValidModel(ulModel) || IsModelTrailer(ulModel)) && ((ulModel - 400) < NUMELMS(ucVehicleTypes)))
    {
        int iVehicleType = ucVehicleTypes[ulModel - 400];
        return VehicleTypes[iVehicleType].szName;
    }
    return szVehicleNameEmpty;
}
