// https://www.youtube.com/watch?v=akFRa58Svug

#include<bits/stdc++.h>

int _capacity;
list<int> cache;
unordered_map<int, pair<int, list<int>::iterator> >mp;

LRUCache::LRUCache(int capacity) {
    cache.clear();
    mp.clear();
    _capacity = capacity;
}

int LRUCache::get(int key) {
    if(mp.find(key) != mp.end()) // if element exists in the  map
    {
        cache.erase(mp[key].second); // remove the element from cache
        cache.push_front(key); // put the element in the front of the cache as this is the most recently used.
        mp[key].second = cache.begin(); // // set the new node postion of that element in the map
        
        return mp[key].first;
    }
    
    return -1;
}

void LRUCache::set(int key, int value) {
    if(mp.find(key) != mp.end())
    {
        cache.erase(mp[key].second); // remove the element
        cache.push_front(key); // put the element in the front of cache
        mp[key] = make_pair(value, cache.begin()); // update the node position in the map.
    } else
    {
		// check the capacity and if exceeded, remove the least recently used from the back of cache.
        if(cache.size() >= _capacity)
        {
            mp.erase(cache.back());
            cache.pop_back();
        }
        // Finally, add the new key in the cache and add in map as well.
        cache.push_front(key);
        mp[key] = make_pair(value, cache.begin());
    }
}
