#ifndef VECTOR
#define VECTOR

#define DEFAULT_CAPACITY 3 // 默认初始容量

typedef int Rank; // 语义化秩

template <typename T>
class Vector {

    protected:

        Rank _size; // 规模
        int _capacity; // 容量
        T* _elem; // 数据域

    // 容量操作
        void expand(); // 空间不足时扩容
        void shrink(); // 装填因子（_size/_capacity）过小时压缩

    // 排序算法
        void bubbleSort( Rank lo, Rank hi ); // 起泡排序
        void selectionSort( Rank lo, Rank hi ); // 选择排序
        void mergeSort( Rank lo, Rank hi ); // 归并排序
        void quickSort( Rank lo, Rank hi ); // 快速排序
        void heapSort( Rank lo, Rank hi ); // 堆排序

    public:

    // 初始化为容量为 c ，规模为 s ，所有元素均为 v 的向量
        Vector( int c = DEFAULT_CAPACITY, int s = 0, T v = 0 ) {
            _elem = new T[_capacity = c];
            for( _size = 0; _size < s; _elem[ _size++ ] = v );
        }
    // 析构函数
        ~Vector() {
            delete [] _elem;
        }

    // 只读访问
        Rank size() const { return _size; } // 规模
        bool empty() const { return !_size; } //判空
        int disordered() const; // 判断向量是否已经排序
        
        Rank find( T const& e, Rank lo, Rank hi ) const; // 无序向量区间查找
        Rank search( T const& e, Rank lo, Rank hi ) const; // 有序向量区间查找

    // 可写访问
        T& operator[] ( Rank r ) const; // 重载下标操作符

        T remove( Rank r ); // 删除秩为 r 的元素
        int remove( Rank lo, Rank hi ); //删除秩在区间 [lo, hi) 之内的元素

        Rank insert( Rank r, T const& e ); // 插入元素
        Rank insert( T const& e ) { return insert( _size, e ); }

        void sort( Rank lo, Rank hi ); // 对 [lo, hi) 排序
        //void sort() { sort( 0, _size ); } // 整体排序

        void unsort( Rank lo, Rank hi ); // 对 [lo, hi) 置乱
        //void unsort() { sort( 0, _size ); } //整体置乱

        int deduplicate(); //无序去重
        int uniquify(); // 有序去重
};

#endif
