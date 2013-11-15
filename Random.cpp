void DefenseOfTheCodeGame::playRound() 
{
                int unitA = random(Player);
                int unitB = random(Computer);
                
		
		if(Player[unitA]->getType() == "splashdamage")
			Player[unitA]->fightAll(Computer);
		else if(Player[unitA]->getType() == "splashheal")
			Player[unitA]->fightAll(Player);
		else
			Player[unitA]->fight(Computer[unitB]);
		
	
		if(Computer[unitB]->getType() == "splashdamage")
			Computer[unitB]->fightAll(Player);
		else if(Computer[unitB]->getType() == "splashheal")
			Computer[unitB]->fightAll(Computer);
		else
			Computer[unitB]->fight(Player[unitA]);
			
		for(int i=0;i<Player.size();++i)
		{
			cout << Player[i]->getHealth() << '|';
		}
		cout << '\n';
		for(int i=0;i<Computer.size();++i)
		{
			cout << Computer[i]->getHealth() << '|';
		}
		cout << '\n';

}
