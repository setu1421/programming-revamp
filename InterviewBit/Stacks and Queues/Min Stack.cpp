vector<int>st, auxst;

MinStack::MinStack() {
    st.clear();
    auxst.clear();
}

void MinStack::push(int x) {
    st.push_back(x);
    if(auxst.empty() || x <= auxst.back())
    {
        auxst.push_back(x);
    }
    
    return;
}

void MinStack::pop() {
    if(!st.empty())
    {
        if(st.back() == auxst.back())
        {
            auxst.pop_back();
        }
        st.pop_back();
    }
    
    return;
}

int MinStack::top() {
    if(st.empty())
    {
        return -1;
    } else
    {
        return st.back();
    }
}

int MinStack::getMin() {
    if(auxst.empty())
    {
        return -1;
    } else
    {
        return auxst.back();
    }
}

