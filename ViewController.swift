//
//  ViewController.swift
//  MatchGame
//
//  Created by Lab i on 2020/3/24.
//  Copyright © 2020 Lab i. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    lazy var game = MatchingGame(numberOfPairsOfCards: (deck.count+1) / 2)
    @IBAction func startGame(_ sender: UIButton) {
    for index in deck.indices{
        deck[index].setTitle("", for: UIControl.State.normal)
        deck[index].backgroundColor = #colorLiteral(red: 1, green: 0.5763723254, blue: 0, alpha: 1)
    }
        //sender.setTitle("", for: UIControl.State.normal)
            //sender.backgroundColor = #colorLiteral(red: 0.9372549057, green: 0.3490196168, blue: 0.1921568662, alpha: 0)
        }
    @IBOutlet var deck: [UIButton]!
    
    @IBOutlet weak var flipCounter: UILabel!
    var flips = 0{
        didSet{
            flipCounter.text = "Flips: \(flips)"
        }
    }
    
   
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    @IBAction func touchCard(_ sender: UIButton) {
        if let cardNumber = deck.index(of: sender){
            game.chooseCard(at: cardNumber)
            updateViewFromModel()
        }else{
            print("This card is not in the collection!")
        }
        flips+=1
    }
    
    func updateViewFromModel(){
        for index in deck.indices{
            let button = deck[index]
            let card = game.cards[index]
            if card.isFaceUp{
                button.setTitle(emoji(for: card), for: UIControl.State.normal)
                button.backgroundColor = #colorLiteral(red: 1, green: 1, blue: 1, alpha: 1)
            }else{
                button.setTitle("", for: UIControl.State.normal)
                button.backgroundColor = #colorLiteral(red: 1, green: 0.5763723254, blue: 0, alpha: 1)//card.isMatched ? #colorLiteral(red: 0.9372549057, green: 0.3490196168, blue: 0.1921568662, alpha: 0) : #colorLiteral(red: 1, green: 0.5763723254, blue: 0, alpha: 1)
            }
        }
    }
    
    
    var emojiChoices = ["👻","🎃","😈","🦇","🙀"]
    func emoji(for card: Card)-> String{
        return "?"
    }


}

