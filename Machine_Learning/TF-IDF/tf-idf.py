#   Text Analysis using TF-IDF

import re
import math

'''
We know that computers are great with numbers but they cannot work out with the natural language. 
So in order to overcome the problem, the text is converted to numbers for analysis. 
One of the most common and popular techniques for this is TF-IDF which stands for Term Frequency and Inverse Document Frequency.

TF(Term Frequency):- Gives the frequency of each word in a document. 
As the number of occurrences of a word increases in a document its value increases for that document.
Basically, if a word appears more times in a document then that word is important to that document.

TF(t) = (Number of times term t appears in a document) / (Total number of terms in the document)

IDF(Inverse Document Frequency):- The Inverse Document Frequency is a measure of how much information the word provides, i.e., if it's common or rare across all documents. 
It calculates how much a word is important for a given set of document. 
The words that occur in fewer documents are more important compared to the words that occur in more documents. 
It helps to find the important words across the documents.

IDF(t) = log( (Total number of documents) / (1 + Number of documents with term t in it ))
(1 is added to the base for coding purposes. It helps to deal with the cases when the term does not appear in any document. 
The fraction term in the log would have a denominator of zero. 
So in order to prevent division by zero 1 is added in the denominator.)

TF-IDF finally gives the importance of a single word in a collection of documents by multiplying the TF of that word in that document with the IDF of that word across the documents.
'''

class tf_idf_analysis:
    """A class to perform TF-IDF analysis on a given set of documents and search a query from the given set of documents.

        variables(type) = Values contained in the variable.

        docs(list of strings) = Contains a list of all the documents as a string.
        terms_tf_idf_score(list of dict) = TF-IDF-Score of all the documents with all words.
        doc_tf(list of dict) = A list containing the Term Frequency of every word in the corresponding document.
        terms_df(dict of list) = Gives the Document Frequency of each term.
    """
    
    def __init__(self, docs):
        """Input: A list of all documents."""    
        self.docs = docs
        self.tf_idf_score = self.make_tf_idf()
    
    def make_tf_idf(self):
        """Makes the TF-IDF score of all the words in all the documents."""

        terms_df, doc_tf, counter, terms_tf_idf_score = {}, [], 0, []
        
        for i in self.docs:
            counter += 1
            tf = self.get_term_frequency(i)
            doc_tf.append(tf)
            
            for j in tf.items():
                if(terms_df.get(j[0], None) == None):
                    terms_df[j[0]] = [counter]
                elif(i not in terms_df[j[0]]):
                    terms_df[j[0]].append(counter)
        
        for i in doc_tf:
            x = {}
            for j in i.items():
                x[j[0]] = self.tf_mul_idf(j[1], len(terms_df.get(j[0], [])))
            terms_tf_idf_score.append(x)
        
        self.terms_tf_idf_score = terms_tf_idf_score
        self.doc_tf = doc_tf
        self.terms_df = terms_df
        
        return terms_tf_idf_score
    
    def tf_mul_idf(self, tf, df):
        """Multiplies the Term Frequency and Inter-Document Frequency to give the correct score."""
        return math.log(1 + tf) * math.log(len(self.docs) / (1 + df))
    
    def get_term_frequency(self, doc):
        """Returns a dictionary containing the frequency of each term in a given document."""
        
        term_freq, total_terms={}, 0
        
        for i in doc.split():
            total_terms+=1
            if(term_freq.get(i, 0) == 0):
                term_freq[i] = 1
            else:
                term_freq[i] += 1

        for i,j in term_freq.items():
            term_freq[i] = j / total_terms

        return term_freq

    def get_doc_no(self, doc):
        """Gets the document number of a given document from the list of documents given."""
        
        counter = 0
        for i in self.docs:
            if(i == doc):
                return counter
            counter += 1
    
    def get_tf_idf_score(self, word, doc):
        """Returns the TF-IDF score of the document."""
        
        tf = self.get_term_frequency(doc)
        ans = self.tf_mul_idf(tf.get(word, 0), len(self.terms_df.get(word, [])))
        return ans

    def top(self, doc_no, n):
        """Returns top-n most important word of the given document number."""
        
        x = self.terms_tf_idf_score[doc_no]
        return sorted(x.items(), key = lambda z: z[1], reverse = True)[:n]
    
    def get_tf_idf_vector(self, doc):
        """Returns the TF-IDF vector of the document."""
        
        tf = self.get_term_frequency(doc)
        vector = {}
        for i in doc.split():
            vector[i] = self.tf_mul_idf(tf.get(i,0), len(self.terms_df.get(i, [])))
        
        return vector
    
    def search_query(self, query):
        """Returns the sorted list of all the relevant docuemnts along with their relevance scores."""
        
        queryvec = self.get_tf_idf_vector(query)
        doc_score = {}
        query_mag = math.sqrt(sum([j[1]**2 for j in queryvec.items()]))
        
        for i in range(len(self.docs)):
            common_words = [j for j in query.split() if j in self.docs[i].split()]
            if(len(common_words) == 0):
                doc_score[i] = 0
            else:
                dot_product = sum([queryvec[j] * self.terms_tf_idf_score[i][j] for j in common_words])
                doc_mag = math.sqrt(sum([j[1]**2 for j in self.terms_tf_idf_score[i].items()]))
                doc_score[i] = dot_product / (query_mag * doc_mag)
        
        sorted_doc_score = sorted(doc_score.items(), key = lambda x: x[1], reverse= True)
        return sorted_doc_score


# 1. First of all, we need a list of all the documents to work on.
document_0 = "China has a strong economy that is growing at a rapid pace. However politically it differs greatly from the US Economy."
document_1 = "At last, China seems serious about confronting an endemic problem: domestic violence and corruption."
document_2 = "Japan's prime minister, Shinzo Abe, is working towards healing the economic turmoil in his own country for his view on the future of his people."
document_3 = "Vladimir Putin is working hard to fix the economy in Russia as the Ruble has tumbled."
document_4 = "What's the future of Abenomics? We asked Shinzo Abe for his views"
document_5 = "Obama has eased sanctions on Cuba while accelerating those against the Russian Economy, even as the Ruble's value falls almost daily."
document_6 = "Vladimir Putin is riding a horse while hunting deer. Vladimir Putin always seems so serious about things - even riding horses. Is he crazy?"

docs = [document_0, document_1, document_2, document_3, document_4, document_5, document_6]

# 2. Next, basic text-processing is done over all the documents.
for i in range(len(docs)):
    docs[i] = ' '.join(docs[i].split())

# 3. Now, an object is made of the class tf_idf_analyis with the list of all pre-processed text.
x = tf_idf_analysis(docs)

# 4. We can also search for a query by doing pre-processing on the text and then passing it on search_query(query).
query = "Vladimir putin"
results = x.search_query(" ".join(query.split()))

print("Query="+query+"\n")

print("Relevant documents=")
for i in results:
    if(i[1]>0):
        print(str(i[1])+"\t"+docs[i[0]])
    else:
        break


'''
Output:

Query=Vladimir putin

Relevant documents=
0.11504239186027004 Vladimir Putin is riding a horse while hunting deer. Vladimir Putin always seems so serious about things - even riding horses. Is he crazy?
0.08963841168732702 Vladimir Putin is working hard to fix the economy in Russia as the Ruble has tumbled.

'''