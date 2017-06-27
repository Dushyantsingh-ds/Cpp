/* Author: Patricia Wilthew.
 * Description: Definition of an Essay Object derived from
 * a GradedActivity Object
 */
#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

class Essay : public GradedActivity
{
    private:
        // Points obtained in the categories:
        int grammar;
        int spelling; 
        int correct_length;   
        int content;    

    public:
        // Default constructor
        Essay()
        { 
            grammar = 0;
            spelling = 0;
            correct_length = 0;
            content = 0;
        }
        
        // Constructor
        Essay(int gr, int sp, int cl, int ct)
        { 
            setScore(gr, sp, cl, ct);
        }
        
        // Accessor functions
        int getGrammarPoints() const
        { 
            return grammar;
        }
        
        int getSpellingPoints() const
        { 
            return spelling;
        }
        
        int getCorrectLengthPoints() const
        { 
            return correct_length; 
        }

        int getContentPoints() const
        {
            return content;
        }

        int getScore() const
        {
            return score;
        }

        virtual char getLetterGrade() const
        {
            getScore();
            return GradedActivity::getLetterGrade();
        }

        // Mutator functions
        void setGrammarPoints(int gr)
        {
            grammar = gr;
        }

        void setSpellingPoints(int sp)
        {
            spelling = sp;
        }

        void setCorrectLengthPoints(int cl)
        {
            correct_length = cl;
        }

        void setContentPoints(int ct)
        {
            content = ct;
        }

        virtual void setScore(int gr, int sp, int cl, int ct) 
        {
            double numeric_score;  // To hold the numeric score
            
            grammar = gr;
            spelling = sp;
            correct_length = cl;
            content = ct;

            numeric_score = gr + sp + cl + ct;
            
            // Call the inherited setScore function to set
            // the numeric score.
            GradedActivity::setScore(numeric_score);
        }
};
#endif
