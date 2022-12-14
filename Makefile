# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 23:01:46 by frcarval          #+#    #+#              #
#    Updated: 2022/06/06 21:08:31 by frcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Client	=	client.c
			
Server	=	my_dup.c\
			my_len.c\
			my_nr_guesser.c\
			server.c

CNAME 	=	Client
SNAME 	=	Server
COBJECTS	=	$(Client:.c=.o)
SOBJECTS	=	$(Server:.c=.o)
GCCW	=	@gcc -Wall -Wextra -Werror


%.o:		%.c
			$(GCCW) -c $^ -o $@
	
all:		$(SNAME) $(CNAME)

$(CNAME): 	$(COBJECTS)
			$(GCCW) $^ -o $@ 

$(SNAME): 	$(SOBJECTS)
			$(GCCW) $^ -o $@ 
			@clear && echo "\033[1;32m  ___  __   _  _  ____  __  __    ____  ____ \n / __)/  \ ( \/ )(  _ \(  )(  )  (  __)(    \ \n( (__(  O )/ \/ \ ) __/ )( / (_/\ ) _)  ) D (\n \___)\__/ \_)(_/(__)  (__)\____/(____)(____/"
clean:		
			@clear && echo "\033[1;33m  ___  __    ____   __   __ _  ____  ____ \n / __)(  )  (  __) / _\ (  ( \(  __)(    \ \n( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n \___)\____/(____)\_/\_/\_)__)(____)(____/"
			@rm -rf $(COBJECTS)
			@rm -rf $(SOBJECTS)

fclean:		
			@clear && echo "\033[1;31m ____  ___  __    ____   __   __ _  ____  ____ \n(  __)/ __)(  )  (  __) / _\ (  ( \(  __)(    \ \n ) _)( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n(__)  \___)\____/(____)\_/\_/\_)__)(____)(____/"
			@rm -rf $(COBJECTS)
			@rm -rf $(SOBJECTS)
			@rm -rf $(CNAME)
			@rm -rf $(SNAME)

re:			fclean all
			@clear && echo "\033[1;31m ____  ___  __    ____   __   __ _  ____  ____ \n(  __)/ __)(  )  (  __) / _\ (  ( \(  __)(    \ \n ) _)( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n(__)  \___)\____/(____)\_/\_/\_)__)(____)(____/\n\n\n\033[1;32m  ___  __   _  _  ____  __  __    ____  ____ \n / __)/  \ ( \/ )(  _ \(  )(  )  (  __)(    \ \n( (__(  O )/ \/ \ ) __/ )( / (_/\ ) _)  ) D (\n \___)\__/ \_)(_/(__)  (__)\____/(____)(____/"

.PHONY:	all clean fclean re