/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:44 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/22 22:15:38 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->top < 1)
		return (1);
	i = 0;
	while (i < a->top)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_reverse(t_stack *a)
{
	int	i;

	if (a->top < 1)
		return (1);
	i = 0;
	while (i < a->top)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}


static void	fill_stack(t_stack *a, int argc, char **argv)
{
	int i;

	i = 1;
	a->top = argc - 2;
	while (i < argc)
	{
		a->data[i - 1] = ft_atoi(argv[argc - i]);
		i++;
	}
}


static void	sort_list(t_stack *a, t_stack *b)
{
 	if (a->top + 1 == 3)
	{
		short_list(a);
	}
	else
		sort_big_stack(a, b);
}



int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc == 1)
		return (1);
	if (wrong_input(argc, argv))
		return (1);
	a.data = ft_calloc((argc - 1), sizeof(int));
	b.data = ft_calloc((argc - 1), sizeof(int));
	if (!a.data || !b.data)
		return (1);
	fill_stack(&a, argc, argv);
	if (is_sorted(&a))
	{
		free(a.data);
		free(b.data);
		ft_printf("Ordenado");
		return (0);
	}
	b.top = -1;

	sort_list(&a, &b);

/*  							// Imprimir el contenido del stack A desde el top hasta el bottom
 							ft_printf("\n");

 							for (int j = a.top; j >= 0; j--) {
								ft_printf("%d ", a.data[j]);
								ft_printf("%d", b.data[j]);
								ft_printf("\n");
							}
							ft_printf("_ _\na b\n");

							ft_printf("%d %d\n", a.top, b.top); */
	free(a.data);
	free(b.data);
	return (0);
}

// ARG="40 20 55 9 53 5 7 90 4 1 50 23 28 79 3 13 101 36 63 98 17"; ./push_swap $ARG | ./checker_Mac $ARG

// ARG="40 20 55 9 53 5 7 90 4 1 50 23 28 79 3 13 101 36 63 98 17"; ./push_swap $ARG | wc -l

// 78 45 23 67 12 89 56 34 90 11 3 82 39 5 27 70 41 99 20 62 36 88 15 74 54 4 33 13 73 29 22 98 1 95 57 10 60 83 77 2 94 46 17 68 75 25 42 80 81 69 63 19 44 40 76 9 26 16 50 31 8 7 24 65 30 14 47 32 97 48 59 91 61 86 52 72 55 35 18 92 37 84 38 49 64 85 87 66 93 58 71 100 53

// 320 135 442 174 451 388 120 249 490 87 305 373 253 166 44 209 67 261 28 475 471 86 494 212 190 7 34 315 96 45 376 178 458 8 16 470 401 148 235 397 472 272 113 118 275 319 198 12 427 469 143 276 268 31 399 440 378 455 289 303 413 415 375 282 284 163 487 72 193 238 118 430 224 194 118 277 327 5 488 285 173 230 56 245 300 265 302 40 294 353 221 397 204 373 99 411 27 257 226 265 493 350 179 324 195 291 152 17 474 373 470 404 184 48 220 314 208 92 390 223 337 306 489 15 414 249 213 263 453 257 315 370 337 468 56 323 233 373 320 144 246 478 162 486 354 171 180 334 129 375 393 436 85 438 215 186 442 459 342 66 493 10 471 469 477 158 99 478 36 450 271 189 420 280 250 438 24 367 465 37 38 86 365 352 103 439 484 371 354 144 35 392 388 484 317 206 98 269 71 237 53 367 288 169 236 482 163 153 302 295 422 91 261 15 203 155 122 26 19 452 130 205 135 254 347 424 36 486 55 373 59 372 368 159 161 70 219 100 58 360 317 447 227 76 189 469 2 326 285 421 455 214 308 484 430 295 65 379 208 62 406 114 168 292 317 183 177 294 239 20 348 392 421 239 78 444 80 79 34 410 342 130 118 1 72 295 63 100 412 299 323 174 185 421 117 298 422 54 317 70 197 258 33 231 60 64 123 389 11 394 161 348 54 294 52 37 482 72 302 446 207 60 313 468 347 418 164 304 389 263 431 159 330 213 430 198 470 475 346 50 153 140 166 171 279 28 36 15 347 238 444 28 460 128 165 174 168 82 235 391 279 325 28 442 431 119 220 485 260 352 118 30 60 377 22 315 373 184 51 230 94 423 493 238 457 191 188 292 450 370 395 179 473 391 83 24 352 147 439 196 118 367 54 434 307 27 394 43 387 277 245 81 233 221 249 153 9 26 40 315 118 77 478 259 465 67 87 1 146 343 345 440 373 458 344 246 229 241 92 228 463 81 195 164 214 109 466 343 104 94 176 74 472 47 267 344 31 116 301 471 53 368 230 72 195 275 158 38 128 165 152 168 486 457 166 122 318 147 258 203 166 31 34 45 267 168 329 19 400 346 20 385 423 200 478 134 197 135 217 118 352 284 78 94 118 115 44 373 368 264 244 84 68 265 270 344 352 56 241 126 71 58 36 399 228 30 135 85 146 31 147 37 375 46 220 373 244 462 297 433 151 203 158 46 460 309 44 383 171 367 112 280 169 138 126 139 384 467 478 92 146 343 383 288 253 152 122 284 106 161 82 128 88 334 305 385 158 77 8 268 285 19 63 122 34 472 190 47 275 22 275 270 220 293 222 490 235 92 230 108 115 16 335 275 161 76 340 74 438 413 199 200 194 375 313 365 263 238 357 48 225 356 485 317 267 210 54 72 394 192 55 40 243 164 105 161 407 394 75 440 166 76 80 246 162 320 36 328 67 155 91 241 70 16 206 217 267 293 365 377 30 280 382 328 218 22 249 202 451 26 218 107 23 334 26 206 371 375 393 420 308 18 19 77 314 143 114 217 81 115 29 266 171 82 116 21 158 52 246 171 18 24 12 421 129 470 182 367 388 97 444 267 383 368 81 159 231 276 418 265 32 83 277 59 447 163 370 354 267 188 404 146 415 26 288 327 400 204 241 146 18 1 18 186 281 314 370 53 476 211 192 358 72 191 465 23 334 77 171 265 38 118 98 26 308 231 16 85 479 129 245 450 113 186 121 207 420 101 131 111 155 370 148 371 80 235 231 478 25 193 199 424 478 265 243 278 124 411 24 405 480 52 475 462 254 250 63 133 109 358 199 103 355 14 442 190 309 92 146 125 141 234 54 91 477 39 15 474 201 145 90 46 376 318 113 73 290 371 317 146 105 71 448 9 156 121 357 187 245 209 307 438 476 393 460 384 266 214 463 177 115 19 51 53 329 48 150 482 51 338 149 372 181 228 86 364 184 70 470 250 155 155 44 180 172 117 184 438 164 77 23 471 380 28 322 466 58 166 107 209 350 239 43 191 155 346 438 366 390 146 130 317 50 275 48 351 122 277 78 192 92 153 115 484 90 338 82 63 182 477 67 3 363 301 393 234 387 420 173 195 35 487 243 237 433 373 237 10 65 251 222 399 28 40 3 236 285 305 76 231 493 137 227 305 163 328 250 234 366 295 389 32 304 71 266 292 466 136 217 33 62 233 258 204 151 288 202 380 279 397 376 177 366 102 382 385 11 153 150 150 186 136 399 340 194 371 453 433 243 232 126 236 389
