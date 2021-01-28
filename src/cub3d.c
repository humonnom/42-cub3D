#include "cub3d.h"

/*******************************************
-function: draw
-ar:	s 		->	structure(t_all)
-return: int (1 or)
-call: ft_draw()
 *******************************************/
void	ft_draw(t_all *s)
{
	t_ray	ray;
	t_hit	hit;

	//struct 초기화//
	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	s->ray = ray;
	s->hit = hit;
	ft_screen(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	free(s->img.ptr);
	free(s->img.adr);
}

/*******************************************
-function: mlx loop
-ar:	s 		->	structure(t_all)
		cub		->	char *, map file name
		save	-> 	save mode(0 or 1)
-return: int (1 or)
-call:	ft_draw()
		ft_parse()
		ft_close()
		ft_bitmap()
		ft_key()
 *******************************************/

int		ft_cubed(t_all s, char *cub, int save)
{
	t_pos	pos;
	t_dir	dir;
	t_pla	pla;

	pos.x = 0;
	pos.y = 0;
	dir.x = 0;
	dir.y = 0;
	pla.x = PLANEX;
	pla.y = PLANEY;
	s.pos = pos;
	s.dir = dir;
	s.pla = pla;
	/////////////init//////////////
	s.mlx.ptr = mlx_init();
	if (ft_parse(&s, cub) == -1)
		return (ft_close(&s, 0));
//	if (save == 1)
//		return (ft_bitmap(&s));
	s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "cub3D");
	ft_draw(&s);
	mlx_hook(s.win.ptr, KEY, 0, ft_key, &s);	
	mlx_hook(s.win.ptr, EXIT_BTN, 0, ft_close, &s);	
	mlx_loop(s.mlx.ptr);
	return (1);
}

/*******************************************
-function: init structures(2)
-ar:	s 		->	structure(t_all)
		cub		->	char *, map file name
		save	-> 	save mode(0 or 1)
-return: non
-call: ft_cubed()
 *******************************************/

void	ft_declare(t_all s, char *cub, int save)
{
	t_map	map;
	t_tex	tex;
	t_spr	*spr;
	t_stk	*stk;

	map.tab = NULL;
	tex.n = NULL;
	tex.s = NULL;
	tex.e = NULL;
	tex.w = NULL;
	tex.i = NULL;
	spr = NULL;
	stk = NULL;
	map.x = 0;
	map.y = 0;
	map.w = 0;
	map.h = 0;
	map.spr = 0;
	tex.c = NONE;
	tex.f = NONE;
	s.map = map;
	s.tex = tex;
	s.spr = spr;
	s.stk =	stk; 
	ft_cubed(s, cub, save);
}


/*******************************************
-function: init structures(1), create t_all
-ar:	cub		->	char *, map file name
		save	-> 	save mode(0 or 1)
-return:	non
-call:	ft_declare()
 *******************************************/

void	ft_init(char *cub, int save)
{
	t_all 	s;
	t_mlx	mlx;
	t_win	win;
	t_img	img;
	t_err	err;

	mlx.ptr = NULL;
	win.ptr = NULL;
	img.ptr = NULL;
	img.adr = NULL;
	win.x = 0;
	win.y = 0;
	img.fsh = 0;
	err.n = 0;
	err.m = 0;
	err.p = 0;
	s.mlx = mlx;
	s.win = win;
	s.img = img;
	s.err = err;
	ft_initd(s, cub, save);
}

void	ft_initd(t_all s, char *cub, int save)
{
	t_tim	tim;
	t_cmr	cmr;
	t_dst	dst;
	t_stp	stp;
	t_scr	scr;

	tim.now = 0;
	tim.old = 0;
	tim.frame = 0;
	tim.ms = 0;
	tim.rs = 0;
	cmr.x = 0;
	cmr.y = 0;
	dst.sx = 0;
	dst.sy = 0;
	dst.dx = 0;
	dst.dy = 0;
	dst.pw = 0;
	stp.x = 0;
	stp.y = 0;
	scr.ds = 0;
	scr.de = 0;
	scr.lh = 0;
	s.tim = tim;
	s.cmr = cmr;
	s.dst = dst;
	s.stp = stp;
	ft_declare(s, cub, save);
}
