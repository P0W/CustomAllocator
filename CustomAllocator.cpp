#include <stdint.h>
#include <stdio.h>

void Assert(const char* expression, const char* file, int line)
{
}

#define ASSERT(exp)  if (!(exp)) Assert(#exp, __FILE__, (int)__LINE__)

#define list_entry(ptr, type, member) ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

typedef struct ListNode_tag
{
   struct ListNode_tag* next;

   struct ListNode_tag* prev;
} ListNode;


void listInit( ListNode* sentinelNode )
{
   ASSERT( sentinelNode );

   sentinelNode->next = sentinelNode;
   sentinelNode->prev = sentinelNode;
}

int32_t listIsEmpty( const ListNode* sentinelNode )
{
   ASSERT( sentinelNode );
   return ( sentinelNode->next == sentinelNode );
}

ListNode* listGetHead( const ListNode* sentinelNode )
{
   ASSERT( sentinelNode );
   ASSERT( !listIsEmpty( sentinelNode ) );

   return sentinelNode->next;
}

ListNode* listGetTail( const ListNode* sentinelNode )
{
   ASSERT( sentinelNode );
   ASSERT( !listIsEmpty( sentinelNode ) );

   return sentinelNode->prev;
}

static void listRemoveNode( ListNode* node )
{
   ASSERT( node );

   node->prev->next = node->next;
   node->next->prev = node->prev;

   node->next = NULL;
   node->prev = NULL;
}

ListNode* listRemoveHead( ListNode* sentinelNode )
{
   ListNode* result;
   ASSERT( !listIsEmpty( sentinelNode ) );

   result = sentinelNode->next;

   listRemoveNode( result );

   return result;
}

ListNode* listRemoveTail( ListNode* sentinelNode )
{
   ListNode* result;
   
   ASSERT( !listIsEmpty( sentinelNode ) );
   result = sentinelNode->prev;
   
   listRemoveNode( result );

   return result;
}

static void listInsert( ListNode* newNode, ListNode* previous, ListNode* next )
{
   ASSERT( newNode );
   ASSERT( previous );
   ASSERT( next );

   previous->next = newNode;
   newNode->prev = previous;
   newNode->next = next;
   next->prev = newNode;
}

void listAddHead( ListNode* sentinelNode, ListNode* nodeToAdd )
{
   listInsert( nodeToAdd, sentinelNode, sentinelNode->next );
}

void listAddTail( ListNode* sentinelNode, ListNode* nodeToAdd )
{
   listInsert( nodeToAdd, sentinelNode->prev, sentinelNode );
}

ListNode* listIteratorStart( const ListNode* sentinelNode )
{
   ASSERT( sentinelNode );

   return sentinelNode->next;
}

int32_t listIsIteratorEnd( const ListNode* sentinelNode, ListNode* currentNode )
{
   ASSERT( sentinelNode );
   ASSERT( currentNode );

   return ( sentinelNode == currentNode ); 
}

ListNode* listIteratorNext( const ListNode* currentNode )
{
   ASSERT( currentNode );

   return currentNode->next;
}

#if 0
typedef struct IntListItem
{
   int32_t value;
   ListNode listNode;
} IntListItem;

static void testListInsertAndRemoveHead()
{
   ListNode list;
   IntListItem list1;
   IntListItem list2;
   IntListItem list3;
   
   listInit( &list );

   list3.value = 3;
   listAddHead( &list, &list3.listNode );

   list2.value = 2;
   listAddHead( &list, &list2.listNode );

   list1.value = 1;
   listAddHead( &list, &list1.listNode );

   ASSERT( list_entry( listRemoveHead( &list ), IntListItem, listNode )->value == 1 );
   ASSERT( list_entry( listRemoveHead( &list ), IntListItem, listNode )->value == 2 );
   ASSERT( list_entry( listRemoveHead( &list ), IntListItem, listNode )->value == 3 );
}

static void testListInsertAndRemoveTail()
{
   ListNode list;
   IntListItem list1;
   IntListItem list2;
   IntListItem list3;
  
   listInit( &list );

   list1.value = 1;
   listAddTail( &list, &list1.listNode );
   
   list2.value = 2;
   listAddTail( &list, &list2.listNode );

   list3.value = 3;
   listAddTail( &list, &list3.listNode );

   ASSERT( list_entry( listRemoveTail( &list ), IntListItem, listNode )->value == 3 );
   ASSERT( list_entry( listRemoveTail( &list ), IntListItem, listNode )->value == 2 );
   ASSERT( list_entry( listRemoveTail( &list ), IntListItem, listNode )->value == 1 );
}

static void testListInsertHeadAndRemoveTail()
{
   ListNode list;
   IntListItem list1;
   IntListItem list2;
   IntListItem list3;
   
   listInit( &list );

   list1.value = 1;
   listAddHead( &list, &list1.listNode );
   
   list2.value = 2;
   listAddHead( &list, &list2.listNode );

   list3.value = 3;
   listAddHead( &list, &list3.listNode );

   ASSERT( list_entry( listRemoveTail( &list ), IntListItem, listNode )->value == 1 );
   ASSERT( list_entry( listRemoveTail( &list ), IntListItem, listNode )->value == 2 );
   ASSERT( list_entry( listRemoveTail( &list ), IntListItem, listNode )->value == 3 );
}

static void testListInsertTailAndRemoveHead()
{
   ListNode list;
   IntListItem list1;
   IntListItem list2;
   IntListItem list3;

   listInit( &list );

   list1.value = 1;
   listAddTail( &list, &list1.listNode );
   
   list2.value = 2;
   listAddTail( &list, &list2.listNode );

   list3.value = 3;
   listAddTail( &list, &list3.listNode );

   ASSERT( list_entry( listRemoveHead( &list ), IntListItem, listNode )->value == 1 );
   ASSERT( list_entry( listRemoveHead( &list ), IntListItem, listNode )->value == 2 );
   ASSERT( list_entry( listRemoveHead( &list ), IntListItem, listNode )->value == 3 );
}

static void testListGetHeadAndTail()
{
   ListNode list;
   IntListItem list1;
   IntListItem list2;
   IntListItem list3;
   IntListItem list4;

   listInit( &list );

   list3.value = 3;
   listAddHead( &list, &list3.listNode );

   list4.value = 4;
   listAddTail( &list, &list4.listNode );

   list2.value = 2;
   listAddHead( &list, &list2.listNode );
    
   list1.value = 1;
   listAddHead( &list, &list1.listNode );

   ASSERT( list_entry( listGetHead( &list ), IntListItem, listNode )->value == 1 );
   ASSERT( list_entry( listGetTail( &list ), IntListItem, listNode )->value == 4 );
}

static void testListIterator()
{
   ListNode list;
   IntListItem list1;
   IntListItem list2;
   IntListItem list3;
   IntListItem list4;
   ListNode* iterator;

   listInit( &list );

   list4.value = 4;
   listAddHead( &list, &list4.listNode );

   list3.value = 3;
   listAddHead( &list, &list3.listNode );

   list2.value = 2;
   listAddHead( &list, &list2.listNode );

   list1.value = 1;
   listAddHead( &list, &list1.listNode );

   iterator = listIteratorStart( &list );
   ASSERT( !listIsIteratorEnd( &list, iterator ) );
   ASSERT( list_entry( iterator, IntListItem, listNode )->value == 1 );

   iterator = listIteratorNext( iterator );
   ASSERT( !listIsIteratorEnd( &list, iterator ) );
   ASSERT( list_entry( iterator, IntListItem, listNode )->value == 2 );
   
   iterator = listIteratorNext( iterator );
   ASSERT( !listIsIteratorEnd( &list, iterator ) );
   ASSERT( list_entry( iterator, IntListItem, listNode )->value == 3 );

   iterator = listIteratorNext( iterator );
   ASSERT( !listIsIteratorEnd( &list, iterator ) );
   ASSERT( list_entry( iterator, IntListItem, listNode )->value == 4 );
   
   iterator = listIteratorNext( iterator );
   ASSERT( listIsIteratorEnd( &list, iterator ) );
}
#endif
   class CustomAllocator
   {
   public:
 
      CustomAllocator( uint32_t bufferSize, uint32_t bufferCount );
  
      virtual ~CustomAllocator();

      void* allocate( uint32_t size );

      void release( void* buffer );

   private:

      CustomAllocator( const CustomAllocator& source ); // Not implemented
      CustomAllocator& operator=( const CustomAllocator& right ); // Not implemented

      ListNode m_freeList;                

      const uint32_t m_bufferSize;        
   };


   	namespace
{
   struct ListItem
   {
      char* buffer;
      ListNode listNode;
   };
}

CustomAllocator::CustomAllocator( uint32_t bufferSize, uint32_t bufferCount )
:  m_bufferSize( bufferSize )
{
   listInit( &m_freeList );

   // Create "bufferCount" buffers of size "bufferSize".  
   // Each buffer is allocated large enough
   // such that the bytes in front of each buffer are large enough to hold a pointer to a ListEntry struct.
   // This is used to get a reference to the ListEntry struct that manages the buffer
  
   for ( uint32_t index = 0; index < bufferCount; ++index )
   {
      char* buffer = new char[sizeof( ListItem ) + bufferSize ];

      ListItem* listItem = (ListItem*) buffer;
      listItem->buffer = buffer + sizeof( ListItem );

      listAddTail( &m_freeList, &listItem->listNode );
   }
}

CustomAllocator::~CustomAllocator()
{
   while ( !listIsEmpty( &m_freeList ) )
   {
      ListItem* listItem = list_entry( listRemoveHead( &m_freeList ), ListItem, listNode );
      delete [] (char*) listItem;
   }
}

void CustomAllocator::release( void* buffer )
{
   // Get a pointer to the list item
   ListItem* listItem = (ListItem*) ( ( (char*) buffer ) - sizeof( ListItem ) );
   listAddTail( &m_freeList, &listItem->listNode );
}



void* CustomAllocator::allocate( uint32_t size )
{
   ASSERT( size <= m_bufferSize );

   void* result = NULL;

   if ( !listIsEmpty( &m_freeList ) )
   {
      result = list_entry( listRemoveHead( &m_freeList ), ListItem, listNode )->buffer;
   }

   return result;
}
