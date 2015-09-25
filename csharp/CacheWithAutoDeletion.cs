using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fall2015
{
    /// <summary>
    /// Design a cache for translation service with auto deletion.
    /// Ref: http://readyforsoftwareinterview.blogspot.com/2013/04/design-cache-with-auto-deletion.html
    /// Requirements:
    /// 1) The cache has limited size
    /// 2) If cache exceeds its capacity, delete the oldest element
    /// 3) If an elements is accessed, treat that as just being added to the cache.
    /// 
    /// Design:
    /// 1) Use Dictionary to cache the elements
    /// 2) Use LinkedList to keep track of new and old elements (just store the key)
    /// ie
    /// - First element in the list is new.
    /// - Last element in the list is old.
    /// </summary>
    class Cache
    {
        private Dictionary<string, Translator> cache;
        private LinkedList<string> lookup;
        private int limit;

        public Cache(int size)
        {
            this.limit = size;
            this.cache = new Dictionary<string, Translator>(size);
            this.lookup = new LinkedList<string>();
        }

        public void Add(Translator t)
        {
            // if cache size exceeds limit, remove the oldest item
            if(this.cache.Count >= this.limit){
                string oldestItem = this.lookup.Last.Value;

                this.cache.Remove(oldestItem);
                this.lookup.RemoveLast();
            }

            // add the item to the cache and as first element to the lookup list.
            this.lookup.AddFirst(t.Key);
            this.cache.Add(t.Key, t);
        }

        public string Get(string key)
        {
            string result = null;

            // if key is found, set the result to translation and move that item
            // to the begining of lookup list.
            if(this.cache.ContainsKey(key))
            {
                result = this.cache[key].Translation;
                this.lookup.Remove(key);
                this.lookup.AddFirst(key);
            }

            return result;
        }
    }

    public class Translator
    {
        public string Key { get; private set; }
        public string Translation { get;  private set; }
        public Translator(string key, string translation)
        {
            this.Key = key;
            this.Translation = translation;
        }

        public static Translator Create(string key, string translation)
        {
            return new Translator(key, translation);
        }
    }

    [TestClass]
    public class CacheWithAutoDeletionTests
    {

        [TestMethod]
        public void TestCacheWithAutoDeletion()
        {
            Cache c = new Cache(3);
            c.Add(Translator.Create("hello", "vanakkam")); // 1st
            c.Add(Translator.Create("flower", "malar")); // 2nd
            c.Add(Translator.Create("food", "sapadu")); // 3rd
            c.Add(Translator.Create("water", "neer")); // 4th

            string helloTranslation = c.Get("hello");
            // "hello" is added first and its the oldest.
            // since we added 4 elements, while max size of cache is 3
            // "hello" should return null
            Assert.IsNull(helloTranslation);

            string flowerTranslation = c.Get("flower");
            Assert.IsTrue(flowerTranslation == "malar");

            // "flower" is accessed, so it is treated as new entry even though it is second oldest
            // adding another element should remove the 3rd element which is "food"
            c.Add(Translator.Create("fire", "nerupu"));
            string foodTranslation = c.Get("food");
            Assert.IsNull(foodTranslation);
        }
    }
}
