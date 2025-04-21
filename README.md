# so_long

12.04		a voir:		- GNL si besoin des fonctions libft perso (voir si diff)

			a faire:	- map.c	->	check_path, path_recursive (a voir comment ->rush02?)
									d'abord verifier si chemin entre player et n_coin,
									ensuite entre le dernier coin et exit
									


		a faire lorsque fini:	- exit_error de check_map (map.c)
								  --> return (1);
									
								- corriger texte erreurs

			
14.04			- voir segfault



15.04		- voir fichiers normi
			- ajouter image autour (voir taille autorisee selon pdf) - game.c > game_init:
					 load_textures_ui, draw_ui, load_textures_ui
					 
			- ajouter compteur graphique + terminal (voir de ou l'appel)
			- ajouter menu (voir de ou l'appel)
			- voir textes d'erreur

			- ! validite map, si pas de coin !


16.04			OK	a adapter pour opti:	
						- player.c:
								draw_tile, update_player_pos
						- render.c:		
								render_frame 

17.04			ok - maperr4 !! (sortie bloquee)
				ok - maperr8 !! (" " dans map)
				ok - maperr8copy3 !! ("J" dans map)

				- voir 15.04 \


19.04:		- supprimer:
					ok	- tour de map
					ok	- animation exit
					ok	- carres bleus

					ok - controler struct et supprimer inutiles (voir dans code)
					ok - supprimer bouts de codes inutiles:
						 (ex: appels exit_map / return 1)

		ok - game.c->init_map_game: 
					if (check_map(game->map, game, m))// -> map.c
						exit_error("check_map", 1, game);// -> utils.c
		

		ok - exit_error, close_game !map_free (si 0 oui, si 1 non) modif partout


			ok - ajouter:
					ok	- compteur terminal
					ok	- verifier qu'il y a un C

			ok - segfault
			- norminette!

			

21.04:			- norminette (render.c)



===============================================================================================

	--- normi:		  fichier		n fonctions		25 lignes 		80 col		normi ok

					- main.c			1											ok
					- game.c			5 				!				!
					- map.c				6				!				!
					- moving.c			4											ok
					- path.c			3
					- player.c			3				!
					- render.c			7				
					- utils.c			3
					