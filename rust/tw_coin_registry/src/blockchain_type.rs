// SPDX-License-Identifier: Apache-2.0
//
// Copyright © 2017 Trust Wallet.

use serde::Deserialize;

/// Blockchain implementation type.
/// Extend this enum when adding new blockchains.
#[derive(Copy, Clone, Debug, Deserialize, PartialEq)]
pub enum BlockchainType {
    // start_of_blockchain_type - USED TO GENERATE CODE
    Aptos,
    Binance,
    Bitcoin,
    BitcoinCash,
    Cosmos,
    Decred,
    Ethereum,
    Greenfield,
    Groestlcoin,
    InternetComputer,
    Komodo,
    Kusama,
    NativeEvmos,
    NativeInjective,
    Pactus,
    Polkadot,
    Polymesh,
    Ripple,
    Ronin,
    Solana,
    Sui,
    TheOpenNetwork,
    Thorchain,
    Zcash,
    // end_of_blockchain_type - USED TO GENERATE CODE
    #[serde(other)]
    Unsupported,
}

impl BlockchainType {
    pub fn is_supported(&self) -> bool {
        !matches!(self, BlockchainType::Unsupported)
    }
}
