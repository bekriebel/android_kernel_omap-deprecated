/*
 * linux/include/asm-arm/arch-omap/display.h
 *
 * Copyright (C) 2008 Nokia Corporation
 * Author: Tomi Valkeinen <tomi.valkeinen@nokia.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __ASM_ARCH_OMAP_DISPLAY_H
#define __ASM_ARCH_OMAP_DISPLAY_H

#include <linux/list.h>
#include <linux/kobject.h>
#include <asm/atomic.h>

#define DISPC_IRQ_FRAMEDONE		(1 << 0)
#define DISPC_IRQ_VSYNC			(1 << 1)
#define DISPC_IRQ_EVSYNC_EVEN		(1 << 2)
#define DISPC_IRQ_EVSYNC_ODD		(1 << 3)
#define DISPC_IRQ_ACBIAS_COUNT_STAT	(1 << 4)
#define DISPC_IRQ_PROG_LINE_NUM		(1 << 5)
#define DISPC_IRQ_GFX_FIFO_UNDERFLOW	(1 << 6)
#define DISPC_IRQ_GFX_END_WIN		(1 << 7)
#define DISPC_IRQ_PAL_GAMMA_MASK	(1 << 8)
#define DISPC_IRQ_OCP_ERR		(1 << 9)
#define DISPC_IRQ_VID1_FIFO_UNDERFLOW	(1 << 10)
#define DISPC_IRQ_VID1_END_WIN		(1 << 11)
#define DISPC_IRQ_VID2_FIFO_UNDERFLOW	(1 << 12)
#define DISPC_IRQ_VID2_END_WIN		(1 << 13)
#define DISPC_IRQ_SYNC_LOST		(1 << 14)
#define DISPC_IRQ_SYNC_LOST_DIGIT	(1 << 15)
#define DISPC_IRQ_WAKEUP		(1 << 16)

enum omap_display_type {
	OMAP_DISPLAY_TYPE_NONE		= 0,
	OMAP_DISPLAY_TYPE_DPI		= 1 << 0,
	OMAP_DISPLAY_TYPE_DBI		= 1 << 1,
	OMAP_DISPLAY_TYPE_SDI		= 1 << 2,
	OMAP_DISPLAY_TYPE_DSI		= 1 << 3,
	OMAP_DISPLAY_TYPE_VENC		= 1 << 4,
};

enum omap_plane {
	OMAP_DSS_GFX	= 0,
	OMAP_DSS_VIDEO1	= 1,
	OMAP_DSS_VIDEO2	= 2
};

enum omap_channel {
	OMAP_DSS_CHANNEL_LCD	= 0,
	OMAP_DSS_CHANNEL_DIGIT	= 1,
};

enum omap_color_mode {
	OMAP_DSS_COLOR_CLUT1	= 1 << 0,  /* BITMAP 1 */
	OMAP_DSS_COLOR_CLUT2	= 1 << 1,  /* BITMAP 2 */
	OMAP_DSS_COLOR_CLUT4	= 1 << 2,  /* BITMAP 4 */
	OMAP_DSS_COLOR_CLUT8	= 1 << 3,  /* BITMAP 8 */
	OMAP_DSS_COLOR_RGB12U	= 1 << 4,  /* RGB12, 16-bit container */
	OMAP_DSS_COLOR_ARGB16	= 1 << 5,  /* ARGB16 */
	OMAP_DSS_COLOR_RGB16	= 1 << 6,  /* RGB16 */
	OMAP_DSS_COLOR_RGB24U	= 1 << 7,  /* RGB24, 32-bit container */
	OMAP_DSS_COLOR_RGB24P	= 1 << 8,  /* RGB24, 24-bit container */
	OMAP_DSS_COLOR_YUV2	= 1 << 9,  /* YUV2 4:2:2 co-sited */
	OMAP_DSS_COLOR_UYVY	= 1 << 10, /* UYVY 4:2:2 co-sited */
	OMAP_DSS_COLOR_ARGB32	= 1 << 11, /* ARGB32 */
	OMAP_DSS_COLOR_RGBA32	= 1 << 12, /* RGBA32 */
	OMAP_DSS_COLOR_RGBX32	= 1 << 13, /* RGBx32 */

	OMAP_DSS_COLOR_GFX_OMAP3 =
		OMAP_DSS_COLOR_CLUT1 | OMAP_DSS_COLOR_CLUT2 |
		OMAP_DSS_COLOR_CLUT4 | OMAP_DSS_COLOR_CLUT8 |
		OMAP_DSS_COLOR_RGB12U | OMAP_DSS_COLOR_ARGB16 |
		OMAP_DSS_COLOR_RGB16 | OMAP_DSS_COLOR_RGB24U |
		OMAP_DSS_COLOR_RGB24P | OMAP_DSS_COLOR_ARGB32 |
		OMAP_DSS_COLOR_RGBA32 | OMAP_DSS_COLOR_RGBX32,

	OMAP_DSS_COLOR_VID_OMAP3 =
		OMAP_DSS_COLOR_RGB12U | OMAP_DSS_COLOR_ARGB16 |
		OMAP_DSS_COLOR_RGB16 | OMAP_DSS_COLOR_RGB24U |
		OMAP_DSS_COLOR_RGB24P | OMAP_DSS_COLOR_ARGB32 |
		OMAP_DSS_COLOR_RGBA32 | OMAP_DSS_COLOR_RGBX32 |
		OMAP_DSS_COLOR_YUV2 | OMAP_DSS_COLOR_UYVY,
};

enum omap_lcd_display_type {
	OMAP_DSS_LCD_DISPLAY_STN,
	OMAP_DSS_LCD_DISPLAY_TFT,
};

enum omap_dss_load_mode {
	OMAP_DSS_LOAD_CLUT_AND_FRAME	= 0,
	OMAP_DSS_LOAD_CLUT_ONLY		= 1,
	OMAP_DSS_LOAD_FRAME_ONLY	= 2,
	OMAP_DSS_LOAD_CLUT_ONCE_FRAME	= 3,
};

enum omap_dss_color_key_type {
	OMAP_DSS_COLOR_KEY_GFX_DST = 0,
	OMAP_DSS_COLOR_KEY_VID_SRC = 1,
};

enum omap_rfbi_te_mode {
	OMAP_DSS_RFBI_TE_MODE_1 = 1,
	OMAP_DSS_RFBI_TE_MODE_2 = 2,
};

enum omap_panel_config {
	OMAP_DSS_LCD_IVS		= 1<<0,
	OMAP_DSS_LCD_IHS		= 1<<1,
	OMAP_DSS_LCD_IPC		= 1<<2,
	OMAP_DSS_LCD_IEO		= 1<<3,
	OMAP_DSS_LCD_RF			= 1<<4,
	OMAP_DSS_LCD_ONOFF		= 1<<5,

	OMAP_DSS_LCD_TFT		= 1<<20,
};

enum omap_dss_venc_type {
	OMAP_DSS_VENC_TYPE_COMPOSITE,
	OMAP_DSS_VENC_TYPE_SVIDEO,
};

struct omap_display;
struct omap_panel;
struct omap_ctrl;

/* RFBI */

struct rfbi_timings {
	int cs_on_time;
	int cs_off_time;
	int we_on_time;
	int we_off_time;
	int re_on_time;
	int re_off_time;
	int we_cycle_time;
	int re_cycle_time;
	int cs_pulse_width;
	int access_time;

	int clk_div;

	u32 tim[5];             /* set by rfbi_convert_timings() */

	int converted;
};

void omap_rfbi_write_command(const void *buf, u32 len);
void omap_rfbi_read_data(void *buf, u32 len);
void omap_rfbi_write_data(const void *buf, u32 len);
void omap_rfbi_write_pixels(const void __iomem *buf, int scr_width,
		u16 x, u16 y,
		u16 w, u16 h);
int omap_rfbi_enable_te(bool enable, unsigned line);
int omap_rfbi_setup_te(enum omap_rfbi_te_mode mode,
			     unsigned hs_pulse_time, unsigned vs_pulse_time,
			     int hs_pol_inv, int vs_pol_inv, int extif_div);

/* DSI */
int dsi_vc_dcs_write(int channel, u8 *data, int len);
int dsi_vc_dcs_write_nosync(int channel, u8 *data, int len);
int dsi_vc_dcs_read(int channel, u8 dcs_cmd, u8 *buf, int buflen);
int dsi_vc_set_max_rx_packet_size(int channel, u16 len);
int dsi_vc_send_null(int channel);

/* Board specific data */
struct omap_dss_display_config {
	enum omap_display_type type;

	union {
		struct {
			u8 data_lines;
		} dpi;

		struct {
			u8 channel;
			u8 data_lines;
		} rfbi;

		struct {
			u8 datapairs;
		} sdi;

		struct {
			u8 clk_lane;
			u8 clk_pol;
			u8 data1_lane;
			u8 data1_pol;
			u8 data2_lane;
			u8 data2_pol;
			unsigned long ddr_clk_hz;
		} dsi;

		struct {
			enum omap_dss_venc_type type;
		} venc;
	} u;

	int panel_reset_gpio;
	int ctrl_reset_gpio;

	int max_backlight_level;

	const char *name;		/* for debug */
	const char *ctrl_name;
	const char *panel_name;

	void *panel_data;
	void *ctrl_data;

	/* platform specific enable/disable */
	int (*panel_enable)(struct omap_display *display);
	void (*panel_disable)(struct omap_display *display);
	int (*ctrl_enable)(struct omap_display *display);
	void (*ctrl_disable)(struct omap_display *display);
	int (*set_backlight)(struct omap_display *display,
			int level);
	int (*get_backlight)(struct omap_display *display);
};

struct device;

/* Board specific data */
struct  omap_dss_board_info {
	unsigned (*get_last_off_on_transaction_id)(struct device *dev);
	int (*dsi_power_up)(void);
	void (*dsi_power_down)(void);
	int num_displays;
	struct omap_dss_display_config *displays[];
};

struct omap_ctrl {
	struct module *owner;

	const char *name;

	int (*init)(struct omap_display *display);
	void (*cleanup)(struct omap_display *display);
	int (*enable)(struct omap_display *display);
	void (*disable)(struct omap_display *display);
	int (*suspend)(struct omap_display *display);
	int (*resume)(struct omap_display *display);
	void (*setup_update)(struct omap_display *display,
			     u16 x, u16 y, u16 w, u16 h);

	int (*enable_te)(struct omap_display *display, bool enable);

	u8 (*get_rotate)(struct omap_display *display);
	int (*set_rotate)(struct omap_display *display, u8 rotate);

	bool (*get_mirror)(struct omap_display *display);
	int (*set_mirror)(struct omap_display *display, bool enable);

	int (*run_test)(struct omap_display *display, int test);
	int (*memory_read)(struct omap_display *display,
			void *buf, size_t size,
			u16 x, u16 y, u16 w, u16 h);

	u8 pixel_size;

	struct rfbi_timings timings;

	void *priv;
};

struct omap_video_timings {
	/* Unit: pixels */
	u16 x_res;
	/* Unit: pixels */
	u16 y_res;
	/* Unit: KHz */
	u32 pixel_clock;
	/* Unit: pixel clocks */
	u16 hsw;	/* Horizontal synchronization pulse width */
	/* Unit: pixel clocks */
	u16 hfp;	/* Horizontal front porch */
	/* Unit: pixel clocks */
	u16 hbp;	/* Horizontal back porch */
	/* Unit: line clocks */
	u16 vsw;	/* Vertical synchronization pulse width */
	/* Unit: line clocks */
	u16 vfp;	/* Vertical front porch */
	/* Unit: line clocks */
	u16 vbp;	/* Vertical back porch */

};

#ifdef CONFIG_OMAP2_DSS_VENC
/* Hardcoded timings for tv modes. Venc only uses these to
 * identify the mode, and does not actually use the configs
 * itself. However, the configs should be something that
 * a normal monitor can also show */
const extern struct omap_video_timings omap_dss_pal_timings;
const extern struct omap_video_timings omap_dss_ntsc_timings;
#endif

struct omap_panel {
	struct module *owner;

	const char *name;

	int (*init)(struct omap_display *display);
	void (*cleanup)(struct omap_display *display);
	int (*remove)(struct omap_display *display);
	int (*enable)(struct omap_display *display);
	void (*disable)(struct omap_display *display);
	int (*suspend)(struct omap_display *display);
	int (*resume)(struct omap_display *display);
	int (*run_test)(struct omap_display *display, int test);

	struct omap_video_timings timings;

	int acbi;	/* ac-bias pin transitions per interrupt */
	/* Unit: line clocks */
	int acb;	/* ac-bias pin frequency */

	enum omap_panel_config config;

	u8 recommended_bpp;

	void *priv;
};

/* XXX perhaps this should be removed */
enum omap_dss_overlay_managers {
	OMAP_DSS_OVL_MGR_LCD,
	OMAP_DSS_OVL_MGR_TV,
};

struct omap_overlay_manager;

enum omap_dss_rotation_type {
	OMAP_DSS_ROT_DMA = 0,
	OMAP_DSS_ROT_VRFB = 1,
};

struct omap_overlay_info {
	bool enabled;

	u32 paddr;
	void __iomem *vaddr;
	u16 screen_width;
	u16 width;
	u16 height;
	enum omap_color_mode color_mode;
	u8 rotation;
	enum omap_dss_rotation_type rotation_type;
	bool mirror;

	u16 pos_x;
	u16 pos_y;
	u16 out_width;	/* if 0, out_width == width */
	u16 out_height;	/* if 0, out_height == height */
};

enum omap_overlay_caps {
	OMAP_DSS_OVL_CAP_SCALE = 1 << 0,
	OMAP_DSS_OVL_CAP_DISPC = 1 << 1,
};

struct omap_overlay {
	struct kobject kobj;
	struct list_head list;

	const char *name;
	int id;
	struct omap_overlay_manager *manager;
	enum omap_color_mode supported_modes;
	struct omap_overlay_info info;
	enum omap_overlay_caps caps;

	int (*set_manager)(struct omap_overlay *ovl,
		struct omap_overlay_manager *mgr);
	int (*unset_manager)(struct omap_overlay *ovl);

	int (*set_overlay_info)(struct omap_overlay *ovl,
			struct omap_overlay_info *info);
	void (*get_overlay_info)(struct omap_overlay *ovl,
			struct omap_overlay_info *info);
};

enum omap_overlay_manager_caps {
	OMAP_DSS_OVL_MGR_CAP_DISPC = 1 << 0,
};

struct omap_overlay_manager {
	struct kobject kobj;
	struct list_head list;

	const char *name;
	int id;
	enum omap_overlay_manager_caps caps;
	struct omap_display *display;
	int num_overlays;
	struct omap_overlay **overlays;
	enum omap_display_type supported_displays;

	int (*set_display)(struct omap_overlay_manager *mgr,
		struct omap_display *display);
	int (*unset_display)(struct omap_overlay_manager *mgr);

	int (*apply)(struct omap_overlay_manager *mgr);

	void (*set_default_color)(struct omap_overlay_manager *mgr, u32 color);
	void (*set_trans_key)(struct omap_overlay_manager *mgr,
		enum omap_dss_color_key_type type,
		u32 trans_key);
	void (*enable_trans_key)(struct omap_overlay_manager *mgr,
		bool enable);
};

enum omap_display_caps {
	OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE = 1 << 0,
};

enum omap_dss_update_mode {
	OMAP_DSS_UPDATE_DISABLED = 0,
	OMAP_DSS_UPDATE_AUTO,
	OMAP_DSS_UPDATE_MANUAL,
};

enum omap_dss_display_state {
	OMAP_DSS_DISPLAY_DISABLED = 0,
	OMAP_DSS_DISPLAY_ACTIVE,
	OMAP_DSS_DISPLAY_SUSPENDED,
};

struct omap_display {
	struct kobject kobj;
	struct list_head list;

	/*atomic_t ref_count;*/
	int ref_count;
	/* helper variable for driver suspend/resume */
	int activate_after_resume;

	enum omap_display_type type;
	const char *name;

	enum omap_display_caps caps;

	struct omap_overlay_manager *manager;

	enum omap_dss_display_state state;

	struct omap_dss_display_config hw_config; /* board specific data */
	struct omap_ctrl *ctrl;			/* static common data */
	struct omap_panel *panel;		/* static common data */

	int (*enable)(struct omap_display *display);
	void (*disable)(struct omap_display *display);

	int (*suspend)(struct omap_display *display);
	int (*resume)(struct omap_display *display);

	void (*get_resolution)(struct omap_display *display,
			u16 *xres, u16 *yres);
	int (*get_recommended_bpp)(struct omap_display *display);

	int (*check_timings)(struct omap_display *display,
			struct omap_video_timings *timings);
	void (*set_timings)(struct omap_display *display,
			struct omap_video_timings *timings);
	void (*get_timings)(struct omap_display *display,
			struct omap_video_timings *timings);
	int (*update)(struct omap_display *display,
			       u16 x, u16 y, u16 w, u16 h);
	int (*sync)(struct omap_display *display);
	int (*wait_vsync)(struct omap_display *display);

	int (*set_update_mode)(struct omap_display *display,
			enum omap_dss_update_mode);
	enum omap_dss_update_mode (*get_update_mode)
		(struct omap_display *display);

	int (*enable_te)(struct omap_display *display, bool enable);
	int (*get_te)(struct omap_display *display);

	u8 (*get_rotate)(struct omap_display *display);
	int (*set_rotate)(struct omap_display *display, u8 rotate);

	bool (*get_mirror)(struct omap_display *display);
	int (*set_mirror)(struct omap_display *display, bool enable);

	int (*run_test)(struct omap_display *display, int test);
	int (*memory_read)(struct omap_display *display,
			void *buf, size_t size,
			u16 x, u16 y, u16 w, u16 h);

	void (*configure_overlay)(struct omap_overlay *overlay);
};

int omap_dss_get_num_displays(void);
struct omap_display *omap_dss_get_display(int no);
void omap_dss_put_display(struct omap_display *display);

void omap_dss_register_ctrl(struct omap_ctrl *ctrl);
void omap_dss_unregister_ctrl(struct omap_ctrl *ctrl);

void omap_dss_register_panel(struct omap_panel *panel);
void omap_dss_unregister_panel(struct omap_panel *panel);

int omap_dss_get_num_overlay_managers(void);
struct omap_overlay_manager *omap_dss_get_overlay_manager(int num);

int omap_dss_get_num_overlays(void);
struct omap_overlay *omap_dss_get_overlay(int num);

typedef void (*omap_dispc_isr_t) (void *arg, u32 mask);
int omap_dispc_register_isr(omap_dispc_isr_t isr, void *arg, u32 mask);
int omap_dispc_unregister_isr(omap_dispc_isr_t isr, void *arg, u32 mask);

int omap_dispc_wait_for_irq_timeout(u32 irqmask, unsigned long timeout);
int omap_dispc_wait_for_irq_interruptible_timeout(u32 irqmask,
		unsigned long timeout);

#endif