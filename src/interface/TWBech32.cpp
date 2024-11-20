// SPDX-License-Identifier: Apache-2.0
//
// Copyright © 2017 Trust Wallet.

#include <TrustWalletCore/TWBech32.h>

#include "../Bech32.h"

#include <string>

using namespace TW;

TWString *_Nonnull TWBech32Encode(TWString* _Nonnull hrp, TWData *_Nonnull data) {
    auto cppHrp = *reinterpret_cast<const std::string*>(hrp);
    auto cppData = *reinterpret_cast<const Data*>(data);
    auto result = Bech32::encode(cppHrp, cppData, Bech32::ChecksumVariant::Bech32);
    return TWStringCreateWithUTF8Bytes(result.c_str());
}

TWData *_Nullable TWBech32Decode(TWString *_Nonnull string) {
    auto cppString = *reinterpret_cast<const std::string*>(string);
    const auto decoded = Bech32::decode(cppString);

    auto data = std::get<1>(decoded);
    if (data.empty()) { // Failed to decode
        return nullptr;
    }

    if (std::get<2>(decoded) != Bech32::ChecksumVariant::Bech32) { // Wrong ChecksumVariant
        return nullptr;
    }

    return TWDataCreateWithBytes(data.data(), data.size());
}
