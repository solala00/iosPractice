//
//  MatchingGame.swift
//  MatchGame
//
//  Created by Lab i on 2020/3/24.
//  Copyright © 2020 Lab i. All rights reserved.
//

import Foundation

class MatchingGame    {
    
    var cards=Array<Card>()
    func chooseCard(at index: Int){
        if cards[index].isFaceUp{
            cards[index].isFaceUp=false
        }else{
            cards[index].isFaceUp = true
        }
    }
    
    init(numberOfPairsOfCards: Int){
        for _ in 1...numberOfPairsOfCards{
            let card = Card()
            cards += [card,card]
        }
        
        // TODO: Shuffle Cards
    }
}
