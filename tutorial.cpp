#include <eosio/eosio.hpp>
#include <eosio/print.hpp>
#include <eosio/asset.hpp>
#include <eosio/system.hpp>
#include <eosio/symbol.hpp>
#include <string>
#include <eosio/crypto.hpp>
#include <eosio/transaction.hpp>

using namespace eosio;

class [[eosio::contract("codetutorial")]] codetutorial : public eosio::contract
{

public:
    using contract::contract;

    [[eosio::action]] void addmessage(name user, uint64_t ID, std::string message)
    {
        require_auth(user);

        check(message.length() >= 10 && message.length() <= 100, "Your message was either too long or too short");

        // emplace info table

        msg_table msgs(get_self(), get_self().value);

            msgs.emplace(get_self(), [&](auto &row)
                         { row.ID = msgs.available_primary_key();
                         
                         row.message = message; });
    } // end addMessage

    // END OF PUBLIC

private:
    struct [[eosio::table]] messages
    {
        /* data */
        uint64_t ID;
        std::string message;
        uint64_t primary_key() const { return ID; }
    };

    using msg_table = eosio::multi_index<"messages"_n, messages>;

    // END OF PRIVATE
};