#include "../Header/Product.hpp"

Product::Product(int idKonfig, bool fromHewan)
{
    setID(idKonfig);
    setKode(ParserProduk::getCode(idKonfig));
    setName(ParserProduk::getName(idKonfig));
    setPrice(ParserProduk::getPrice(idKonfig));
    setTipeObject("PRODUCT");
    type = ParserProduk::getType(idKonfig);
    addedWeight = ParserProduk::getAddedWeight(idKonfig);
    origin = ParserProduk::getOrigin(idKonfig);
    isFromHewan = fromHewan;
}

bool Product::fromHewan()
{
    return isFromHewan;
}

int Product::getAddedWeight()
{
    return addedWeight;
}

string Product::getOrigin()
{
    return origin;
}

string Product::getType()
{
    return type;
}

Product &Product::operator=(const Product &other)
{
    GameObject::operator=(other);
    type = other.type;
    isFromHewan = other.isFromHewan;
    addedWeight = other.addedWeight;
    origin = other.origin;
    return *this;
}

bool Product::operator==(const Product &other)
{
    return GameObject::operator==(other);
}