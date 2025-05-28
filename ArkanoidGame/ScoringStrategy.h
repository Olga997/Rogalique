#pragma once
#include "Block.h"

namespace ArkanoidGame
{
    class Block;
    class ScoringStrategy 
    {
    public:
        virtual ~ScoringStrategy() = default;
        virtual int calculateScore(const std::shared_ptr<Block>& block) const = 0;
    };

    //  онкретные стратегии дл€ разных типов блоков
    class BasicBlockScoring : public ScoringStrategy {
    public:
        int calculateScore(const std::shared_ptr<Block>& block) const override
        {           
            return  block->GetScorePoint();
        }
    };
}
