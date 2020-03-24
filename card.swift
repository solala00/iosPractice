//
//  card.swift
//  MatchGame
//
//  Created by Lab i on 2020/3/24.
//  Copyright © 2020 Lab i. All rights reserved.
//

import Foundation
struct Card{
    var isFaceUp = false
    var isMatched = false
    var identifier: Int
    static var idFactory = 0
    
    static func getUniqueIdentifier() -> Int{
        idFactory += 1
        return idFactory
    }
    
    init(){
        self.identifier = Card.getUniqueIdentifier()
    }
}
