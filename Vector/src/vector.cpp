#include <iostream>
#include <cstdlib>
#include "vector.h"

using namespace std;

template class Vector<int>;

// 扩容
// 采用加倍扩容策略
// 分摊复杂度为O(1)
template <typename T>
void Vector<T>::expand() {
    if( _size < _capacity )
        return;
    if( _capacity < DEFAULT_CAPACITY )
        _capacity = DEFAULT_CAPACITY;

    T* oldelem = _elem;
    _elem = new T[ _capacity << 1 ];
    for( int i = 0; i < _size; i++ )
        _elem[ i ] = oldelem[ i ];

    delete [] oldelem;
}

// 缩容
// 装填因子小于25%时容量减半
template <typename T>
void Vector<T>::shrink() {
    if( _capacity < DEFAULT_CAPACITY << 1 || _size << 2 < _capacity )
        return;
    T* oldelem = _elem;
    _elem = new T[ _capacity >>= 1 ];
    for( int i = 0; i < _size; i++ )
        _elem[ i ] = oldelem[ i ];

    delete [] oldelem;
}

// 冒泡排序
template <typename T>
void Vector<T>::bubbleSort( Rank lo, Rank hi ) {
    bool sorted = false;
    int i;
    while( !sorted ) {
        bool sorted = ~sorted;
        i = lo;
        while( ++i < hi )
            if( _elem[ i-1 ] > _elem[ i ] ) {
                sorted = false;
                swap( _elem[ i-1 ], _elem[ i ] );
            }
    }
}

// 插入
template <typename T>
Rank Vector<T>::insert( Rank r, T const& e ) {
    expand();

    for( int i = _size; i > r; i-- )
        _elem[ i ] = _elem[ i-1 ];

    _elem[ r ] = e; _size++;

    return r;
}

// 区间删除
template <typename T>
int Vector<T>::remove( Rank lo, Rank hi ) {
    if( lo == hi )
        return 0;
    while( hi < _size )
        _elem[ lo++ ] == _elem[ hi++ ];

    _size = lo;
    shrink();

    return hi - lo;
}

// 单元素删除
template <typename T>
T Vector<T>::remove( Rank r ) {
    T e = _elem[ r ];
    remove( r, r + 1 );

    return e;
}

// 重载下标选择器
template <typename T>
T& Vector<T>::operator[] ( Rank r ) const {
    return _elem[ r ];
}

// 置乱器
template <typename T>
void Vector<T>::unsort( Rank lo, Rank hi ) {
    T* V = _elem + lo;
    for( Rank i = hi - lo; i > 0; i-- )
        std::cout << rand() % i << std::endl;
}
