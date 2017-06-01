#include <stdint.h>
#include <stdio.h>

//https://godbolt.org/#z:OYLghAFBqd5QCxAYwPYBMCmBRdBLAF1QCcAaPECAKxAEZSBnVAV2OUxAHIBSAJgGY8AO2QAbZlgDU3fgGEGBfEIIA6BDOzcADAEE%2BgkeKkz5ivKjUbte3QDdUedJJ0MGmYgQhohCycgQAhsQAVJKYAB4ADsSYruZCpH6oPgR%2BgSGSAGZ4opiJwqmiwpgAlNbcAOwAQuUVACLluvpY2UKYzgDKHdgASgAqEBGRJZKSeJmSEGCQQyUjLm4eEPpDiQD6awBiAJIAMtgbiRAFJRu72wByB2tlTU0CLcWSRQprmMrEAJ4QkQRkkgRPpE8pIALaYUEAI3cIyggOBkmCJSg/iCiORv2IJQAtBBmD48MA2k5RMlgMi%2BAA2OFA9pIrQ4jTgqEwuaNHTwzAtSQKYjMZCpXZ4BQXDCYNYEALAWo1XSjHl/fmC4UEUVYCVS0JtcIEGSymw6eW8pWSIUisUa4ChaKYWx62p1U0qtWYe13A32RzPFXbISECBO81YUJuZTFUQuyS3PTVazynRdXoDHnvAjhyNlfj6uOjUNptoRsXYjTa1IyR159Nit2G3OpqtYYv8bA22zSfgV%2BsFl01yoNd0Ffi8CXehTbBjYUG/b5JFKB1VikNdzCFqTRyr6%2BOJ/oByvdsVRmvymIEVhCSYpsP7xsliJljvly/5lcZ3v1dlmhfB0cEADimAIAAJTAAnQANvF8T8XSXK8XwPddYzlUYE26HcnwbdpM03ZDt2TaYXgIcdJ2nXdl1XTDDyzdljwAs90OvTAm2wUs337A0oMXH9/wIPoAhycDkkg51OL3OC1xlHNOlQ5NRPIyjsKkpMA3wn0JynQFSNguSRiw6jRhPOjZJdJjW1Y9kFACNNkEkT0SRVHoIVQWxMBdAMOO/IR4IkpDFLQzzxKo915X8xiNFbJjS3bR0Qoiu8j1GGLbx1EyYjbR9EubUzAoNYKiyS%2B9HQuABVXZdniyQMpbVKoskYrSrM913MwUICIc0EnMwYDQLc4TvyMrymkQ2t52gyQYgYZhRF1bKt2k5SwAIoj1Jnfq13kvSxtiSaCvosTQubFjssk1rHOc1zNomqb1qC/TaOIc9xu2hr2N65qfzajreP4kaRLI19BoUprQkeqbysklClMkFSxzUkjdu067hpBnbVv2qrbTBnyTvas6xQDZHEckgz7oup6jvfd0LKsmyHDsscfHcTwfo8zAAHcXUSIHJFbcxmAYTnXq1O9DwB8HcIDNp2a8macLm7nUt5hhEdmyHIt0m75dtRXYp1GrJZ7GWKrZ4ywuqx8eZYBhyv1vKDuF9K4sN0sUttPXjercm2OsWyfx0dB0C6sDmbe1GBaDN6Qr6VA/acBCFMWhmlgqsUo5jxJQ/hk27d19WYy9uxad9/2vtEHrw5g59yLDr8I5T6P/ZFmN459ROmcj%2Bv0HTv7bfR2wu6019PY/QWf22Ah3EskgOklJOIOVcvM4Gpuxbl1HCZ84nz1RnXpuzCmDUHYdClUseJ6IYhmKDufg4rjDq9G5BWBiZR/uXnyIbQtfc5VtDH%2BIZ%2Ba7ryRndc8mlK6RnLI%2BP%2BADB5VGkINfOOguaLXHsQSexALh3gEnOLm0DUyvw3CvSGeCX7S2zBvEBfgn74J7odPeiDrCcm5MaAUkhfQEE/KfUE3lhqHxHLYAI4hXSGyaj%2BA29C2HKE4ePbhR1dBUzwNZH248FCcNbjoIQ6APrOUDhAOOklREEXKuw6REIfy0GMVIn0Mify8EsRw6xZiCL8ExsNBO/ppC8EpARIB8pnEqAEUImqLjDYERjrozx3iVSJCpP4gisCNoEV4AEwRzB2iPjsaElU4SQJB1idEyJSSVDxLIYklUtAUlBMfBYrJCgcndUKQU/JCgKklICuQ4aH9kwETeB8Gc2MOoROaakEoiQTGONBIkNpmEmKBLSVFapytZaQx6amL4AYBk6NyQGYZUYxlWLHDIqZr0oyzNSekh8HZJC8CWb5bpKpel/H6fZU6nVtmNN8KMyRDjDkQmOeHU5Gg5kXIaFc/ghN97WAUUowuKifmEXUZo7RmAS56J4fKQxKp7GmNBOY7FEzbH4t%2Bbi5x8Vjotw8bs3O5KWmVPmdU8qYTi58VLh8ggMSvEEVaSc7%2BowaUEGScCmqmTm51OZd9YZHKokKGSdM3xox/FCsfCE0VBAY6orZVKuJPLezv3Fj%2BR56z3qvI1VS/Z8KuH/MAYyZsSrLmOnBbyu5GyHlrOeQoZFprOUqj2d8nFVqMxnKqfa65tyukuteG6iNBBPUsp2d6z55r/ViPgkG%2BlIbaAQsQdCmmXo4VqMWEBXJGitEmrjfonymKFBEsIjYrlNauGEsNuM4lP4VWSX5b6SlCaRm6rceUulILJA1NVfUvJPatUDrlU6/lgrznCsZdk/2QyJ1stlTquR/aFD8EHcExdYqA7vMlWynd06%2B0/3uZGvp0bY0Sp7b6ltta/kprXGmkFiynXhoNVG41OMUVxrZQ%2Bg5T7JkvpmUC%2BdkCrk3M/fq1Z17f2fQA2av1EyA2pog8G0FDqs3mUlNTZRsQLWtxLiW5FuiK3DSrbvSSj7G31ubcB%2BjKoRW0aY3WlU7aNbuKZlS89CqB12sdCO/l6rkOruGdygFM6sYsd3Rk/darxWsuPcM9d0n%2BNtvk2CxTYm73SvZSe4pG6OkXujYa91MbXkroM0Bi1RywOAttZBjNYa4OuoQ5st5DSUN0Yc9Ot9CzoNublvBp5N7rNHvvV8vzz6AuYfTdhyQjrnpQvw4o3NTh80qm4oHEtqLKMYpOUYxj9mnHlIbRxmVlXyvbpqySlUAAWTTPH422epbJ7d2mHW6eXVFgzk6utns3X4pr3XJDNdqUp9AXqBtssa8ZjTI2BMyvG6xzr02bMEUGwKxb1ryrwK3QQCpQnh29cPT5iTPapP7eW8679nmcsAS2z6mL7G4s8sC1B4TIWVkefC1xACs2fFvbK6B%2BLzmsOPka7hym6WYV5qI6YtB580Wi0rcVrFpWcV4uxwSpJ9W22E4IpNwGI9CBnxIC1ilvHovU4UAt07pPRN9cu3N4ZC3humZWwQHdp2uNHbHW17bRmudlNW6d9bgvWfjvZz29Tt3ufmPGyJjbQvNVspuwkjWFOUckBqigynxBp5BFp%2B18qX7oaEQYKfPXF9NHC4Kbr9BUZftoTC0a5358k1occza7AQmP2aa9/rx8hu7eYJ1AGEPxA3d4QWifVB6DL6O4UPkJP59XewdC/9z3GeSA%2B%2BJeh19CX33BZk7w/Psew%2BOIj1gsYVe4/zUWjbqvKeNcx6zxb9zV6Acx8LyB4v4HIeJeVfKhvRuDe1/QZHpmnfs%2BQyt%2BOW3yeHcd8bzpbvOfe956NwPy1fuvshphxX%2BUnea%2B/Lr1Hifdum%2Bj1b0b9vx75%2Bw5yqMMQARXCSFkHzIgoIdCiCkjIDoIdpDTyiRDMCQhFDIAgBxiSTyg/4KCoD/6AGoDAGo6SDMB8KpCQjMCZCZDuAdB4AABeIIWBygQ4I4uB%2BB7gsgLAygSy8BowtgeAHgzAgikgAAfogX/gAUAegmindvKLZKEIIvwePAGOQbzkfDyCQZhJpsIYXDELkJ/pgAGCIZINQQQbHh1sNNEHgAIuPLARrAgb/sgXwWgQIbOL4DweYagegVTl4jyCwGwPIVmJIAAPQeG1SoCpB4BTi5DgjKBchMHf5mEoHiGOGUiSCoDAh27ljYI2HhEWEOHEBUhjSEgIC9ruFeE%2BF%2BEBEQipghEmGjCiKghrCZAxCYCfh6jyh1H1F1EbTyjXxSGUGpDlFaGEFyG1ENGHbyh9h9odpaAACcQgAQ4IDAkQAQ7A6KuYiorCOKoBCkzR6QoQnRaRhsRWAK0yYM74Q87othERlh58IAIAhxKRVhrRMh6xRBpBiQVxVBeB2hdB%2BIvaugIAowHRTxXRpBAYNxchjchCG2XaZu5RlRmA1Rr2mmuRsgMQlk6SvAvA6xLxygfANy6xSsqAEwDAAJaJ/xpBaJKgfKPkuR2A0xCAmh3xsewokgYhxxXIzwQQwA7Q7wLAwA6gJJ3hE0/gAIgQqQBACA7QkInwKiYw54lRyQqQWJYQ5JlJNBseQQ7QogTJLJnkzA7JAIqAkgCAqAogTgAQ3MDgwRseRAtJ84zETyCofIAoKgkkuRfQCANJNJfMDJppzJqQBpMQ2h7w7AmpvJ7Qn4FpXwVpJoAplkYIAQYxzJSsApQpVJOYkkmQ%2Bukh2BYpWA4QNUWgtRwg6Z7Ysgcpzx9Bu8niNQvAVQOZEQjc/RYB9RqIGQ6xbsrMaQQQ3AAArFUDiaQViWXCBq7nwHAviekq2aCkrlsSBi1ASo%2BBADikiAWe4AdjzlwkxA2Y%2BCuWWbIV2ZkD2Y2roQ0UyjNuJpSGCVUZ%2BDtkuRoGLj5AMQguyOcfYegqcdwckfeajoVqMKzI6bkBeEvrDBpJEseRCZ%2BF3leTWXUTOaPDYhfgQBZhFn%2BjZgBZCYmvOAfpecNPKFgLkOPNIO2W2Y6F4KsSMIbrIgpNeXnOyD7HeZEcQKccoSBG4OobTGsVSYCaBbkdxGaZEEaagn6bGT%2BBPtwhjsShOa2lOTObCBePhUELOQ2SMNiBuZgN2chTYpvlNnpipl4ghaeWyuec2KhaReyN7IxWEUgUcakacXSegWoZgamZ2fIejp0vqrZXmY%2BF8fKbcW4UrhoQTI%2BHVGVHduMN%2BQnjDMRH%2BVSJpa9lWXyqBTRJdDtB7pZuRv1uFUhcmhDtgOsbsYgjRKeCTMjM9JwKMqIFwK2ZwKQEIFwFoKVagFwLIP2f2c4awL6foLQKVQQBVQVaMgANYgCtmtkqAAAcWgtAjWWg/AtA/AWgWgrZwx/AFQpARVnAjWpV5VnAlVpA1VnApVDAIAWgpAbVq1BVpAcAsASAaAU4OQ7g5AlAZ1kQF11FwADAYxkQDAOp7K2QU07g21EAkI7VpAZ1QRBAAA8kIKIJ8L9fgDEAKAYbEL9QUCuO1aMrEWmIJFwNiAoOgOWMgHVWWbQMQaMNiIDfwFtS4ewHQIVcVctb9RteEP1ZSNiJSDDsAMgNZBAI9QEM9a9bCLgIQKHgIPQN/sgbdbkNXnzSUK1QjV1SAI1gtrQMMf1dNZSLTcMcMSNZSPwPNVwEtWVVTVwFtTtXtRLRrZwLwJTQdetbrQbQdXMKQM5MQDickFLUAA%3D%3D

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
