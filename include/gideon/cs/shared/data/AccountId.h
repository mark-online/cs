#pragma once

#include <sne/srpc/RpcContainers.h>

namespace gideon {

/// Account Id.
typedef uint64_t AccountId;
const AccountId invalidAccountId = 0;

/// is valid AccountId
inline bool isValidAccountId(AccountId accountId)
{
    return invalidAccountId != accountId;
}


/// AccountId list
typedef sne::srpc::RVector<AccountId> AccountIds;

} // namespace gideon {
