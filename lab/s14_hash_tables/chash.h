//
// Created by Juan Diego Castro Padilla on 23/06/22.
//

#ifndef S14_HASH_TABLES_CHASH_H
#define S14_HASH_TABLES_CHASH_H

#include <functional>
#include <forward_list>

template <typename T>
size_t hash_function(T key, size_t m){
    std::hash<T> pre_hash_fun;
    auto numeric_key = pre_hash_fun(key);
    return numeric_key % m;
}

template <typename KeyType, typename ValueType>
using item_t = std::pair<KeyType, ValueType>;

template <typename KeyType, typename ValueType>
using chain_t = std::forward_list<item_t<KeyType, ValueType>>;

template <typename KeyType, typename ValueType>
class close_hash_table{

private:

    size_t m {0};
    chain_t<KeyType, ValueType>* table {nullptr};

public:

    explicit close_hash_table(size_t m): m{m} {
        table = new chain_t<KeyType, ValueType>[m];
    }

    close_hash_table(const close_hash_table<KeyType, ValueType>& other): m(other.m) {
        table = new chain_t<KeyType, ValueType>[m];
        std::copy(other.table, other.table+m, table);
    }

    close_hash_table<KeyType, ValueType>& operator = (const close_hash_table<KeyType, ValueType>& other){
        if (&other == this){
            return *this;
        }
        delete [] table;
        m = other.m;
        table = new chain_t<KeyType, ValueType>[m];
        std::copy(other.table, other.table+m, table);
        return *this;
    }

    ~close_hash_table(){
        delete [] table;
    }

    std::pair<item_t<KeyType, ValueType>*, bool> insert(const item_t<KeyType, ValueType>& item){
        // Search the slot
        size_t index_slot = hash_function(item.first, m);

        // Search the reference to chain
        auto& chain = table[index_slot];

        // Search the key
        auto it = std::find_if(std::begin(chain), std::end(chain), [item](const item_t<KeyType, ValueType>& current){
            return item.first == current.first;
        });

        if (it == end(chain)){
            chain.push_front(item);
            return {&chain.front(), true};
        }
        return {nullptr, false};
    }

    std::pair<item_t<KeyType, ValueType>*, bool> find(const KeyType& key){
        // Search the slot
        size_t index_slot = hash_function(key, m);

        // Search the reference to chain
        auto& chain = table[index_slot];

        // Search the key
        auto it = std::find_if(std::begin(chain), std::end(chain), [key](const item_t<KeyType, ValueType>& current){
            return key == current.first;
        });

        if (it != end(chain)){
            return {&(*it), true};
        }
        return {nullptr, false};
    }

    bool remove(const KeyType& key){
        // Search the slot
        size_t index_slot = hash_function(key, m);

        // Search the reference to chain
        auto& chain = table[index_slot];

        auto old_size = std::distance(std::begin(chain), std::end(chain));
        chain.remove_if([key](const item_t<KeyType, ValueType>& current){
            return key == current.first;
        });
        auto new_size = std::distance(std::begin(chain), std::end(chain));

        return new_size < old_size;
    }

};


#endif //S14_HASH_TABLES_CHASH_H
