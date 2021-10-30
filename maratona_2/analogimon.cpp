#include <iostream>
#include <vector>

std::vector<int> guild_point;
std::vector<int> guild;

int findGuild(int player)
{
    if (player != guild[player])
        guild[player] = findGuild(guild[player]);
    return guild[player];
}

void mergeGuilds(int guild1, int guild2)
{
    int clan1 = findGuild(guild1);
    int clan2 = findGuild(guild2);

    if (clan1 != clan2)
    {
        guild[clan1] = clan2;
        guild_point[clan2] += guild_point[clan1];
    }
}

int main()
{
    int num_players, num_acoes;
    while (std::cin >> num_players >> num_acoes)
    {
        guild.clear();
        guild.resize(num_players);

        guild_point.clear();
        guild_point.resize(num_players);

        for (int i = 0; i < num_players; i++)
        {
            guild[i] = i;
            guild_point[i] = 1;
        }

        int wins = 0;

        for (int i = 0; i < num_acoes; i++)
        {
            int guild1, guild2;
            std::cin >> guild1 >> guild2;
            guild1 -= 1;
            guild2 -= 1;

            mergeGuilds(guild1, guild2);
        }
        int meu;
        std::cin >> meu;

        int meu_digi = findGuild(meu-1);
        std::cout << guild_point[meu_digi] << "\n";
    }

    return 0;
}