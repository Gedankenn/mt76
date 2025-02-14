/* SPDX-License-Identifier: ISC */
/* Copyright (C) 2019 MediaTek Inc. */

#ifndef __MT7615_REGS_H
#define __MT7615_REGS_H

enum mt7615_reg_base {
	MT_TOP_CFG_BASE,
	MT_HW_BASE,
	MT_DMA_SHDL_BASE,
	MT_PCIE_REMAP_2,
	MT_ARB_BASE,
	MT_HIF_BASE,
	MT_CSR_BASE,
	MT_PLE_BASE,
	MT_PSE_BASE,
	MT_CFG_BASE,
	MT_AGG_BASE,
	MT_TMAC_BASE,
	MT_RMAC_BASE,
	MT_DMA_BASE,
	MT_PF_BASE,
	MT_WTBL_BASE_ON,
	MT_WTBL_BASE_OFF,
	MT_LPON_BASE,
	MT_MIB_BASE,
	MT_WTBL_BASE_ADDR,
	MT_PCIE_REMAP_BASE2,
	MT_TOP_MISC_BASE,
	MT_EFUSE_ADDR_BASE,
	MT_PP_BASE,
	__MT_BASE_MAX,
};

#define MT_HW_INFO_BASE			((dev)->reg_map[MT_HW_BASE])
#define MT_HW_INFO(ofs)			(MT_HW_INFO_BASE + (ofs))
#define MT_HW_REV			MT_HW_INFO(0x000)
#define MT_HW_CHIPID			MT_HW_INFO(0x008)
#define MT_TOP_STRAP_STA		MT_HW_INFO(0x010)
#define MT_TOP_3NSS			BIT(24)

#define MT_TOP_OFF_RSV			0x1128
#define MT_TOP_OFF_RSV_FW_STATE		GENMASK(18, 16)

#define MT_TOP_MISC2			((dev)->reg_map[MT_TOP_CFG_BASE] + 0x134)
#define MT_TOP_MISC2_FW_STATE		GENMASK(2, 0)

#define MT7663_TOP_MISC2_FW_STATE	GENMASK(3, 1)
#define MT_TOP_MISC2_FW_PWR_ON		BIT(1)

#define MT_MCU_BASE			0x2000
#define MT_MCU(ofs)			(MT_MCU_BASE + (ofs))

#define MT_MCU_PCIE_REMAP_1		MT_MCU(0x500)
#define MT_MCU_PCIE_REMAP_1_OFFSET	GENMASK(17, 0)
#define MT_MCU_PCIE_REMAP_1_BASE	GENMASK(31, 18)
#define MT_PCIE_REMAP_BASE_1		0x40000

#define MT_MCU_PCIE_REMAP_2		((dev)->reg_map[MT_PCIE_REMAP_2])
#define MT_MCU_PCIE_REMAP_2_OFFSET	GENMASK(18, 0)
#define MT_MCU_PCIE_REMAP_2_BASE	GENMASK(31, 19)
#define MT_PCIE_REMAP_BASE_2		((dev)->reg_map[MT_PCIE_REMAP_BASE2])

#define MT_MCU_CIRQ_BASE		0xc0000
#define MT_MCU_CIRQ(ofs)		(MT_MCU_CIRQ_BASE + (ofs))

#define MT_MCU_CIRQ_IRQ_SEL(n)		MT_MCU_CIRQ((n) << 2)

#define MT_HIF(ofs)			((dev)->reg_map[MT_HIF_BASE] + (ofs))
#define MT_HIF_RST			MT_HIF(0x100)
#define MT_HIF_LOGIC_RST_N		BIT(4)

#define MT_PDMA_SLP_PROT		MT_HIF(0x154)
#define MT_PDMA_AXI_SLPPROT_ENABLE	BIT(0)
#define MT_PDMA_AXI_SLPPROT_RDY		BIT(16)

#define MT_PDMA_BUSY_STATUS		MT_HIF(0x168)
#define MT_PDMA_TX_IDX_BUSY		BIT(2)
#define MT_PDMA_BUSY_IDX		BIT(31)

#define MT_WPDMA_TX_RING0_CTRL0		MT_HIF(0x300)
#define MT_WPDMA_TX_RING0_CTRL1		MT_HIF(0x304)

#define MT7663_MCU_PCIE_REMAP_2_OFFSET	GENMASK(15, 0)
#define MT7663_MCU_PCIE_REMAP_2_BASE	GENMASK(31, 16)

#define MT_HIF2_BASE			0xf0000
#define MT_HIF2(ofs)			(MT_HIF2_BASE + (ofs))
#define MT_PCIE_IRQ_ENABLE		MT_HIF2(0x188)
#define MT_PCIE_DOORBELL_PUSH		MT_HIF2(0x1484)

#define MT_CFG_LPCR_HOST		MT_HIF(0x1f0)
#define MT_CFG_LPCR_HOST_FW_OWN		BIT(0)
#define MT_CFG_LPCR_HOST_DRV_OWN	BIT(1)

#define MT_MCU2HOST_INT_STATUS		MT_HIF(0x1f0)
#define MT_MCU2HOST_INT_ENABLE		MT_HIF(0x1f4)

#define MT7663_MCU_INT_EVENT		MT_HIF(0x108)
#define MT_MCU_INT_EVENT		MT_HIF(0x1f8)
#define MT_MCU_INT_EVENT_PDMA_STOPPED	BIT(0)
#define MT_MCU_INT_EVENT_PDMA_INIT	BIT(1)
#define MT_MCU_INT_EVENT_SER_TRIGGER	BIT(2)
#define MT_MCU_INT_EVENT_RESET_DONE	BIT(3)

#define MT_INT_SOURCE_CSR		MT_HIF(0x200)
#define MT_INT_MASK_CSR			MT_HIF(0x204)
#define MT_DELAY_INT_CFG		MT_HIF(0x210)

#define MT_INT_RX_DONE(_n)		BIT(_n)
#define MT_INT_RX_DONE_ALL		GENMASK(1, 0)
#define MT_INT_TX_DONE_ALL		GENMASK(19, 4)
#define MT_INT_TX_DONE(_n)		BIT((_n) + 4)
#define MT7663_INT_MCU_CMD		BIT(29)
#define MT_INT_MCU_CMD			BIT(30)

#define MT_WPDMA_GLO_CFG		MT_HIF(0x208)
#define MT_WPDMA_GLO_CFG_TX_DMA_EN	BIT(0)
#define MT_WPDMA_GLO_CFG_TX_DMA_BUSY	BIT(1)
#define MT_WPDMA_GLO_CFG_RX_DMA_EN	BIT(2)
#define MT_WPDMA_GLO_CFG_RX_DMA_BUSY	BIT(3)
#define MT_WPDMA_GLO_CFG_DMA_BURST_SIZE	GENMASK(5, 4)
#define MT_WPDMA_GLO_CFG_TX_WRITEBACK_DONE	BIT(6)
#define MT_WPDMA_GLO_CFG_BIG_ENDIAN	BIT(7)
#define MT_WPDMA_GLO_CFG_TX_BT_SIZE_BIT0	BIT(9)
#define MT_WPDMA_GLO_CFG_BYPASS_TX_SCH		BIT(9) /* MT7622 */
#define MT_WPDMA_GLO_CFG_MULTI_DMA_EN	GENMASK(11, 10)
#define MT_WPDMA_GLO_CFG_FIFO_LITTLE_ENDIAN	BIT(12)
#define MT_WPDMA_GLO_CFG_TX_BT_SIZE_BIT21	GENMASK(23, 22)
#define MT_WPDMA_GLO_CFG_SW_RESET	BIT(24)
#define MT_WPDMA_GLO_CFG_FIRST_TOKEN_ONLY	BIT(26)
#define MT_WPDMA_GLO_CFG_OMIT_TX_INFO	BIT(28)

#define MT_WPDMA_RST_IDX		MT_HIF(0x20c)

#define MT_WPDMA_MEM_RNG_ERR		MT_HIF(0x224)

#define MT_MCU_CMD			MT_HIF(0x234)
#define MT_MCU_CMD_CLEAR_FW_OWN		BIT(0)
#define MT_MCU_CMD_STOP_PDMA_FW_RELOAD	BIT(1)
#define MT_MCU_CMD_STOP_PDMA		BIT(2)
#define MT_MCU_CMD_RESET_DONE		BIT(3)
#define MT_MCU_CMD_RECOVERY_DONE	BIT(4)
#define MT_MCU_CMD_NORMAL_STATE		BIT(5)
#define MT_MCU_CMD_LMAC_ERROR		BIT(24)
#define MT_MCU_CMD_PSE_ERROR		BIT(25)
#define MT_MCU_CMD_PLE_ERROR		BIT(26)
#define MT_MCU_CMD_PDMA_ERROR		BIT(27)
#define MT_MCU_CMD_PCIE_ERROR		BIT(28)
#define MT_MCU_CMD_ERROR_MASK		(GENMASK(5, 1) | GENMASK(28, 24))
#define MT7663_MCU_CMD_ERROR_MASK	GENMASK(5, 2)

#define MT_TX_RING_BASE			MT_HIF(0x300)
#define MT_RX_RING_BASE			MT_HIF(0x400)

#define MT_WPDMA_GLO_CFG1		MT_HIF(0x500)
#define MT_WPDMA_TX_PRE_CFG		MT_HIF(0x510)
#define MT_WPDMA_RX_PRE_CFG		MT_HIF(0x520)
#define MT_WPDMA_ABT_CFG		MT_HIF(0x530)
#define MT_WPDMA_ABT_CFG1		MT_HIF(0x534)

#define MT_CSR(ofs)			((dev)->reg_map[MT_CSR_BASE] + (ofs))
#define MT_CONN_HIF_ON_LPCTL		MT_CSR(0x000)

#define MT_PLE(ofs)			((dev)->reg_map[MT_PLE_BASE] + (ofs))

#define MT_PLE_PG_HIF0_GROUP		MT_PLE(0x110)
#define MT_HIF0_MIN_QUOTA		GENMASK(11, 0)
#define MT_PLE_FL_Q0_CTRL		MT_PLE(0x1b0)
#define MT_PLE_FL_Q1_CTRL		MT_PLE(0x1b4)
#define MT_PLE_FL_Q2_CTRL		MT_PLE(0x1b8)
#define MT_PLE_FL_Q3_CTRL		MT_PLE(0x1bc)

#define MT_PLE_AC_QEMPTY(ac, n)		MT_PLE(0x300 + 0x10 * (ac) + \
					       ((n) << 2))

#define MT_PSE(ofs)			((dev)->reg_map[MT_PSE_BASE] + (ofs))
#define MT_PSE_PG_HIF0_GROUP		MT_PSE(0x110)
#define MT_HIF0_MIN_QUOTA		GENMASK(11, 0)
#define MT_PSE_PG_HIF1_GROUP		MT_PSE(0x118)
#define MT_HIF1_MIN_QUOTA		GENMASK(11, 0)
#define MT_PSE_QUEUE_EMPTY		MT_PSE(0x0b4)
#define MT_HIF_0_EMPTY_MASK		BIT(16)
#define MT_HIF_1_EMPTY_MASK		BIT(17)
#define MT_HIF_ALL_EMPTY_MASK		GENMASK(17, 16)
#define MT_PSE_PG_INFO			MT_PSE(0x194)
#define MT_PSE_SRC_CNT			GENMASK(27, 16)

#define MT_PP(ofs)			((dev)->reg_map[MT_PP_BASE] + (ofs))
#define MT_PP_TXDWCNT			MT_PP(0x0)
#define MT_PP_TXDWCNT_TX0_ADD_DW_CNT	GENMASK(7, 0)
#define MT_PP_TXDWCNT_TX1_ADD_DW_CNT	GENMASK(15, 8)

#define MT_WF_PHY_BASE			0x82070000
#define MT_WF_PHY(ofs)			(MT_WF_PHY_BASE + (ofs))

#define MT_WF_PHY_WF2_RFCTRL0(n)	MT_WF_PHY(0x1900 + (n) * 0x400)
#define MT_WF_PHY_WF2_RFCTRL0_LPBCN_EN	BIT(9)

#define MT_WF_PHY_R0_PHYMUX_5(_phy)	MT_WF_PHY(0x0614 + ((_phy) << 9))
#define MT7663_WF_PHY_R0_PHYMUX_5	MT_WF_PHY(0x0414)

#define MT_WF_PHY_R0_PHYCTRL_STS0(_phy)	MT_WF_PHY(0x020c + ((_phy) << 9))
#define MT_WF_PHYCTRL_STAT_PD_OFDM	GENMASK(31, 16)
#define MT_WF_PHYCTRL_STAT_PD_CCK	GENMASK(15, 0)

#define MT7663_WF_PHY_R0_PHYCTRL_STS0(_phy)	MT_WF_PHY(0x0210 + ((_phy) << 12))

#define MT_WF_PHY_R0_PHYCTRL_STS5(_phy)	MT_WF_PHY(0x0220 + ((_phy) << 9))
#define MT_WF_PHYCTRL_STAT_MDRDY_OFDM	GENMASK(31, 16)
#define MT_WF_PHYCTRL_STAT_MDRDY_CCK	GENMASK(15, 0)

#define MT7663_WF_PHY_R0_PHYCTRL_STS5(_phy)	MT_WF_PHY(0x0224 + ((_phy) << 12))

#define MT_WF_PHY_MIN_PRI_PWR(_phy)	MT_WF_PHY((_phy) ? 0x084 : 0x229c)
#define MT_WF_PHY_PD_OFDM_MASK(_phy)	((_phy) ? GENMASK(24, 16) : \
					 GENMASK(28, 20))
#define MT_WF_PHY_PD_OFDM(_phy, v)	((v) << ((_phy) ? 16 : 20))
#define MT_WF_PHY_PD_BLK(_phy)		((_phy) ? BIT(25) : BIT(19))

#define MT7663_WF_PHY_MIN_PRI_PWR(_phy)	MT_WF_PHY((_phy) ? 0x2aec : 0x22f0)

#define MT_WF_PHY_RXTD_BASE		MT_WF_PHY(0x2200)
#define MT_WF_PHY_RXTD(_n)		(MT_WF_PHY_RXTD_BASE + ((_n) << 2))

#define MT7663_WF_PHY_RXTD(_n)		(MT_WF_PHY(0x25b0) + ((_n) << 2))

#define MT_WF_PHY_RXTD_CCK_PD(_phy)	MT_WF_PHY((_phy) ? 0x2314 : 0x2310)
#define MT_WF_PHY_PD_CCK_MASK(_phy)	(_phy) ? GENMASK(31, 24) : \
					 GENMASK(8, 1)
#define MT_WF_PHY_PD_CCK(_phy, v)	((v) << ((_phy) ? 24 : 1))

#define MT7663_WF_PHY_RXTD_CCK_PD(_phy)	MT_WF_PHY((_phy) ? 0x2350 : 0x234c)

#define MT_WF_PHY_RXTD2_BASE		MT_WF_PHY(0x2a00)
#define MT_WF_PHY_RXTD2(_n)		(MT_WF_PHY_RXTD2_BASE + ((_n) << 2))

#define MT_WF_PHY_RFINTF3_0(_n)		MT_WF_PHY(0x1100 + (_n) * 0x400)
#define MT_WF_PHY_RFINTF3_0_ANT		GENMASK(7, 4)

#define MT_WF_CFG_BASE			((dev)->reg_map[MT_CFG_BASE])
#define MT_WF_CFG(ofs)			(MT_WF_CFG_BASE + (ofs))

#define MT_CFG_CCR			MT_WF_CFG(0x000)
#define MT_CFG_CCR_MAC_D1_1X_GC_EN	BIT(24)
#define MT_CFG_CCR_MAC_D0_1X_GC_EN	BIT(25)
#define MT_CFG_CCR_MAC_D1_2X_GC_EN	BIT(30)
#define MT_CFG_CCR_MAC_D0_2X_GC_EN	BIT(31)

#define MT_WF_AGG_BASE			((dev)->reg_map[MT_AGG_BASE])
#define MT_WF_AGG(ofs)			(MT_WF_AGG_BASE + (ofs))

#define MT_AGG_ARCR			MT_WF_AGG(0x010)
#define MT_AGG_ARCR_INIT_RATE1		BIT(0)
#define MT_AGG_ARCR_RTS_RATE_THR	GENMASK(12, 8)
#define MT_AGG_ARCR_RATE_DOWN_RATIO	GENMASK(17, 16)
#define MT_AGG_ARCR_RATE_DOWN_RATIO_EN	BIT(19)
#define MT_AGG_ARCR_RATE_UP_EXTRA_TH	GENMASK(22, 20)

#define MT_AGG_ARUCR(_band)		MT_WF_AGG(0x018 + (_band) * 0x100)
#define MT_AGG_ARDCR(_band)		MT_WF_AGG(0x01c + (_band) * 0x100)
#define MT_AGG_ARxCR_LIMIT_SHIFT(_n)	(4 * (_n))
#define MT_AGG_ARxCR_LIMIT(_n)		GENMASK(2 + \
					MT_AGG_ARxCR_LIMIT_SHIFT(_n), \
					MT_AGG_ARxCR_LIMIT_SHIFT(_n))

#define MT_AGG_ASRCR0			MT_WF_AGG(0x060)
#define MT_AGG_ASRCR1			MT_WF_AGG(0x064)
#define MT_AGG_ASRCR_RANGE(val, n)	(((val) >> ((n) << 3)) & GENMASK(5, 0))

#define MT_AGG_ACR(_band)		MT_WF_AGG(0x070 + (_band) * 0x100)
#define MT_AGG_ACR_NO_BA_RULE		BIT(0)
#define MT_AGG_ACR_NO_BA_AR_RULE	BIT(1)
#define MT_AGG_ACR_PKT_TIME_EN		BIT(2)
#define MT_AGG_ACR_CFEND_RATE		GENMASK(15, 4)
#define MT_AGG_ACR_BAR_RATE		GENMASK(31, 20)

#define MT_AGG_SCR			MT_WF_AGG(0x0fc)
#define MT_AGG_SCR_NLNAV_MID_PTEC_DIS	BIT(3)

#define MT_WF_ARB_BASE			((dev)->reg_map[MT_ARB_BASE])
#define MT_WF_ARB(ofs)			(MT_WF_ARB_BASE + (ofs))

#define MT_ARB_RQCR			MT_WF_ARB(0x070)
#define MT_ARB_RQCR_RX_START		BIT(0)
#define MT_ARB_RQCR_RXV_START		BIT(4)
#define MT_ARB_RQCR_RXV_R_EN		BIT(7)
#define MT_ARB_RQCR_RXV_T_EN		BIT(8)
#define MT_ARB_RQCR_BAND_SHIFT		16

#define MT_ARB_SCR			MT_WF_ARB(0x080)
#define MT_ARB_SCR_TX0_DISABLE		BIT(8)
#define MT_ARB_SCR_RX0_DISABLE		BIT(9)
#define MT_ARB_SCR_TX1_DISABLE		BIT(10)
#define MT_ARB_SCR_RX1_DISABLE		BIT(11)

#define MT_WF_TMAC_BASE			((dev)->reg_map[MT_TMAC_BASE])
#define MT_WF_TMAC(ofs)			(MT_WF_TMAC_BASE + (ofs))

#define MT_TMAC_CDTR			MT_WF_TMAC(0x090)
#define MT_TMAC_ODTR			MT_WF_TMAC(0x094)
#define MT_TIMEOUT_VAL_PLCP		GENMASK(15, 0)
#define MT_TIMEOUT_VAL_CCA		GENMASK(31, 16)

#define MT_TMAC_TRCR(_band)		MT_WF_TMAC((_band) ? 0x070 : 0x09c)
#define MT_TMAC_TRCR_CCA_SEL		GENMASK(31, 30)
#define MT_TMAC_TRCR_SEC_CCA_SEL	GENMASK(29, 28)

#define MT_TMAC_ICR(_band)		MT_WF_TMAC((_band) ? 0x074 : 0x0a4)
#define MT_IFS_EIFS			GENMASK(8, 0)
#define MT_IFS_RIFS			GENMASK(14, 10)
#define MT_IFS_SIFS			GENMASK(22, 16)
#define MT_IFS_SLOT			GENMASK(30, 24)

#define MT_TMAC_CTCR0			MT_WF_TMAC(0x0f4)
#define MT_TMAC_CTCR0_INS_DDLMT_REFTIME	GENMASK(5, 0)
#define MT_TMAC_CTCR0_INS_DDLMT_DENSITY	GENMASK(15, 12)
#define MT_TMAC_CTCR0_INS_DDLMT_EN	BIT(17)
#define MT_TMAC_CTCR0_INS_DDLMT_VHT_SMPDU_EN	BIT(18)

#define MT_WF_RMAC_BASE			((dev)->reg_map[MT_RMAC_BASE])
#define MT_WF_RMAC(ofs)			(MT_WF_RMAC_BASE + (ofs))

#define MT_WF_RFCR(_band)		MT_WF_RMAC((_band) ? 0x100 : 0x000)
#define MT_WF_RFCR_DROP_STBC_MULTI	BIT(0)
#define MT_WF_RFCR_DROP_FCSFAIL		BIT(1)
#define MT_WF_RFCR_DROP_VERSION		BIT(3)
#define MT_WF_RFCR_DROP_PROBEREQ	BIT(4)
#define MT_WF_RFCR_DROP_MCAST		BIT(5)
#define MT_WF_RFCR_DROP_BCAST		BIT(6)
#define MT_WF_RFCR_DROP_MCAST_FILTERED	BIT(7)
#define MT_WF_RFCR_DROP_A3_MAC		BIT(8)
#define MT_WF_RFCR_DROP_A3_BSSID	BIT(9)
#define MT_WF_RFCR_DROP_A2_BSSID	BIT(10)
#define MT_WF_RFCR_DROP_OTHER_BEACON	BIT(11)
#define MT_WF_RFCR_DROP_FRAME_REPORT	BIT(12)
#define MT_WF_RFCR_DROP_CTL_RSV		BIT(13)
#define MT_WF_RFCR_DROP_CTS		BIT(14)
#define MT_WF_RFCR_DROP_RTS		BIT(15)
#define MT_WF_RFCR_DROP_DUPLICATE	BIT(16)
#define MT_WF_RFCR_DROP_OTHER_BSS	BIT(17)
#define MT_WF_RFCR_DROP_OTHER_UC	BIT(18)
#define MT_WF_RFCR_DROP_OTHER_TIM	BIT(19)
#define MT_WF_RFCR_DROP_NDPA		BIT(20)
#define MT_WF_RFCR_DROP_UNWANTED_CTL	BIT(21)

#define MT_WF_RMAC_MORE(_band)		MT_WF_RMAC((_band) ? 0x124 : 0x024)
#define MT_WF_RMAC_MORE_MUAR_MODE	GENMASK(31, 30)

#define MT_WF_RFCR1(_band)		MT_WF_RMAC((_band) ? 0x104 : 0x004)
#define MT_WF_RFCR1_DROP_ACK		BIT(4)
#define MT_WF_RFCR1_DROP_BF_POLL	BIT(5)
#define MT_WF_RFCR1_DROP_BA		BIT(6)
#define MT_WF_RFCR1_DROP_CFEND		BIT(7)
#define MT_WF_RFCR1_DROP_CFACK		BIT(8)

#define MT_CHFREQ(_band)		MT_WF_RMAC((_band) ? 0x130 : 0x030)

#define MT_WF_RMAC_MAR0			MT_WF_RMAC(0x025c)
#define MT_WF_RMAC_MAR1			MT_WF_RMAC(0x0260)
#define MT_WF_RMAC_MAR1_ADDR		GENMASK(15, 0)
#define MT_WF_RMAC_MAR1_START		BIT(16)
#define MT_WF_RMAC_MAR1_WRITE		BIT(17)
#define MT_WF_RMAC_MAR1_IDX		GENMASK(29, 24)
#define MT_WF_RMAC_MAR1_GROUP		GENMASK(31, 30)

#define MT_WF_RMAC_MIB_TIME0		MT_WF_RMAC(0x03c4)
#define MT_WF_RMAC_MIB_RXTIME_CLR	BIT(31)
#define MT_WF_RMAC_MIB_RXTIME_EN	BIT(30)

#define MT_WF_RMAC_MIB_AIRTIME0		MT_WF_RMAC(0x0380)

#define MT_WF_RMAC_MIB_TIME5		MT_WF_RMAC(0x03d8)
#define MT_WF_RMAC_MIB_TIME6		MT_WF_RMAC(0x03dc)
#define MT_MIB_OBSSTIME_MASK		GENMASK(23, 0)

#define MT_WF_DMA_BASE			((dev)->reg_map[MT_DMA_BASE])
#define MT_WF_DMA(ofs)			(MT_WF_DMA_BASE + (ofs))

#define MT_DMA_DCR0			MT_WF_DMA(0x000)
#define MT_DMA_DCR0_MAX_RX_LEN		GENMASK(15, 2)
#define MT_DMA_DCR0_DAMSDU_EN		BIT(16)
#define MT_DMA_DCR0_RX_VEC_DROP		BIT(17)
#define MT_DMA_DCR0_RX_HDR_TRANS_EN	BIT(19)

#define MT_DMA_RCFR0(_band)		MT_WF_DMA(0x070 + (_band) * 0x40)
#define MT_DMA_RCFR0_MCU_RX_MGMT	BIT(2)
#define MT_DMA_RCFR0_MCU_RX_CTL_NON_BAR	BIT(3)
#define MT_DMA_RCFR0_MCU_RX_CTL_BAR	BIT(4)
#define MT_DMA_RCFR0_MCU_RX_TDLS	BIT(19)
#define MT_DMA_RCFR0_MCU_RX_BYPASS	BIT(21)
#define MT_DMA_RCFR0_RX_DROPPED_UCAST	GENMASK(25, 24)
#define MT_DMA_RCFR0_RX_DROPPED_MCAST	GENMASK(27, 26)

#define MT_WF_PF_BASE			((dev)->reg_map[MT_PF_BASE])
#define MT_WF_PF(ofs)			(MT_WF_PF_BASE + (ofs))

#define MT_WF_PFCR			MT_WF_PF(0x000)
#define MT_WF_PFCR_TDLS_EN		BIT(9)

#define MT_WTBL_BASE(dev)		((dev)->reg_map[MT_WTBL_BASE_ADDR])
#define MT_WTBL_ENTRY_SIZE		256

#define MT_WTBL_OFF_BASE		((dev)->reg_map[MT_WTBL_BASE_OFF])
#define MT_WTBL_OFF(n)			(MT_WTBL_OFF_BASE + (n))

#define MT_WTBL_W0_KEY_IDX		GENMASK(24, 23)
#define MT_WTBL_W0_RX_KEY_VALID		BIT(26)
#define MT_WTBL_W0_RX_IK_VALID		BIT(27)

#define MT_WTBL_W2_KEY_TYPE		GENMASK(7, 4)

#define MT_WTBL_UPDATE			MT_WTBL_OFF(0x030)
#define MT_WTBL_UPDATE_WLAN_IDX		GENMASK(7, 0)
#define MT_WTBL_UPDATE_RXINFO_UPDATE	BIT(11)
#define MT_WTBL_UPDATE_ADM_COUNT_CLEAR	BIT(12)
#define MT_WTBL_UPDATE_RATE_UPDATE	BIT(13)
#define MT_WTBL_UPDATE_TX_COUNT_CLEAR	BIT(14)
#define MT_WTBL_UPDATE_BUSY		BIT(31)

#define MT_TOP_MISC(ofs)		((dev)->reg_map[MT_TOP_MISC_BASE] + (ofs))
#define MT_CONN_ON_MISC			MT_TOP_MISC(0x1140)
#define MT_TOP_MISC2_FW_N9_RDY		BIT(2)

#define MT_WTBL_ON_BASE			((dev)->reg_map[MT_WTBL_BASE_ON])
#define MT_WTBL_ON(_n)			(MT_WTBL_ON_BASE + (_n))

#define MT_WTBL_RICR0			MT_WTBL_ON(0x010)
#define MT_WTBL_RICR1			MT_WTBL_ON(0x014)

#define MT_WTBL_RIUCR0			MT_WTBL_ON(0x020)

#define MT_WTBL_RIUCR1			MT_WTBL_ON(0x024)
#define MT_WTBL_RIUCR1_RATE0		GENMASK(11, 0)
#define MT_WTBL_RIUCR1_RATE1		GENMASK(23, 12)
#define MT_WTBL_RIUCR1_RATE2_LO		GENMASK(31, 24)

#define MT_WTBL_RIUCR2			MT_WTBL_ON(0x028)
#define MT_WTBL_RIUCR2_RATE2_HI		GENMASK(3, 0)
#define MT_WTBL_RIUCR2_RATE3		GENMASK(15, 4)
#define MT_WTBL_RIUCR2_RATE4		GENMASK(27, 16)
#define MT_WTBL_RIUCR2_RATE5_LO		GENMASK(31, 28)

#define MT_WTBL_RIUCR3			MT_WTBL_ON(0x02c)
#define MT_WTBL_RIUCR3_RATE5_HI		GENMASK(7, 0)
#define MT_WTBL_RIUCR3_RATE6		GENMASK(19, 8)
#define MT_WTBL_RIUCR3_RATE7		GENMASK(31, 20)

#define MT_WTBL_W5_CHANGE_BW_RATE	GENMASK(7, 5)
#define MT_WTBL_W5_SHORT_GI_20		BIT(8)
#define MT_WTBL_W5_SHORT_GI_40		BIT(9)
#define MT_WTBL_W5_SHORT_GI_80		BIT(10)
#define MT_WTBL_W5_SHORT_GI_160		BIT(11)
#define MT_WTBL_W5_BW_CAP		GENMASK(13, 12)
#define MT_WTBL_W5_MPDU_FAIL_COUNT	GENMASK(25, 23)
#define MT_WTBL_W5_MPDU_OK_COUNT	GENMASK(28, 26)
#define MT_WTBL_W5_RATE_IDX		GENMASK(31, 29)

#define MT_WTBL_W27_CC_BW_SEL		GENMASK(6, 5)

#define MT_LPON(_n)			((dev)->reg_map[MT_LPON_BASE] + (_n))

#define MT_LPON_TCR0(_n)		MT_LPON(0x010 + ((_n) * 4))
#define MT_LPON_TCR2(_n)		MT_LPON(0x0f8 + ((_n) - 2) * 4)
#define MT_LPON_TCR_MODE		GENMASK(1, 0)
#define MT_LPON_TCR_READ		GENMASK(1, 0)
#define MT_LPON_TCR_WRITE		BIT(0)
#define MT_LPON_TCR_ADJUST		BIT(1)

#define MT_LPON_UTTR0			MT_LPON(0x018)
#define MT_LPON_UTTR1			MT_LPON(0x01c)

#define MT_WF_MIB_BASE			(dev->reg_map[MT_MIB_BASE])
#define MT_WF_MIB(_band, ofs)		(MT_WF_MIB_BASE + (ofs) + (_band) * 0x200)

#define MT_WF_MIB_SCR0			MT_WF_MIB(0, 0)
#define MT_MIB_SCR0_AGG_CNT_RANGE_EN	BIT(21)

#define MT_MIB_M0_MISC_CR(_band)	MT_WF_MIB(_band, 0x00c)

#define MT_MIB_SDR3(_band)		MT_WF_MIB(_band, 0x014)
#define MT_MIB_SDR3_FCS_ERR_MASK	GENMASK(15, 0)

#define MT_MIB_SDR9(_band)		MT_WF_MIB(_band, 0x02c)
#define MT_MIB_SDR9_BUSY_MASK		GENMASK(23, 0)

#define MT_MIB_SDR14(_band)		MT_WF_MIB(_band, 0x040)
#define MT_MIB_AMPDU_MPDU_COUNT		GENMASK(23, 0)

#define MT_MIB_SDR15(_band)		MT_WF_MIB(_band, 0x044)
#define MT_MIB_AMPDU_ACK_COUNT		GENMASK(23, 0)

#define MT_MIB_SDR16(_band)		MT_WF_MIB(_band, 0x048)
#define MT_MIB_SDR16_BUSY_MASK		GENMASK(23, 0)

#define MT_MIB_SDR36(_band)		MT_WF_MIB(_band, 0x098)
#define MT_MIB_SDR36_TXTIME_MASK	GENMASK(23, 0)
#define MT_MIB_SDR37(_band)		MT_WF_MIB(_band, 0x09c)
#define MT_MIB_SDR37_RXTIME_MASK	GENMASK(23, 0)

#define MT_MIB_MB_SDR0(_band, n)	MT_WF_MIB(_band, 0x100 + ((n) << 4))
#define MT_MIB_RTS_RETRIES_COUNT_MASK	GENMASK(31, 16)
#define MT_MIB_RTS_COUNT_MASK		GENMASK(15, 0)

#define MT_MIB_MB_SDR1(_band, n)	MT_WF_MIB(_band, 0x104 + ((n) << 4))
#define MT_MIB_BA_MISS_COUNT_MASK	GENMASK(15, 0)
#define MT_MIB_ACK_FAIL_COUNT_MASK	GENMASK(31, 16)

#define MT_MIB_ARNG(n)			MT_WF_MIB(0, 0x4b8 + ((n) << 2))

#define MT_TX_AGG_CNT(_band, n)		MT_WF_MIB(_band, 0xa8 + ((n) << 2))

#define MT_DMA_SHDL(ofs)		(dev->reg_map[MT_DMA_SHDL_BASE] + (ofs))

#define MT_DMASHDL_BASE			0x5000a000
#define MT_DMASHDL_OPTIONAL		0x008
#define MT_DMASHDL_PAGE			0x00c

#define MT_DMASHDL_REFILL		0x010

#define MT_DMASHDL_PKT_MAX_SIZE		0x01c
#define MT_DMASHDL_PKT_MAX_SIZE_PLE	GENMASK(11, 0)
#define MT_DMASHDL_PKT_MAX_SIZE_PSE	GENMASK(27, 16)

#define MT_DMASHDL_GROUP_QUOTA(_n)	(0x020 + ((_n) << 2))
#define MT_DMASHDL_GROUP_QUOTA_MIN	GENMASK(11, 0)
#define MT_DMASHDL_GROUP_QUOTA_MAX	GENMASK(27, 16)

#define MT_DMASHDL_SCHED_SET0		0x0b0
#define MT_DMASHDL_SCHED_SET1		0x0b4

#define MT_DMASHDL_Q_MAP(_n)		(0x0d0 + ((_n) << 2))
#define MT_DMASHDL_Q_MAP_MASK		GENMASK(3, 0)
#define MT_DMASHDL_Q_MAP_SHIFT(_n)	(4 * ((_n) % 8))

#define MT_LED_BASE_PHYS		0x80024000
#define MT_LED_PHYS(_n)			(MT_LED_BASE_PHYS + (_n))

#define MT_LED_CTRL			MT_LED_PHYS(0x00)

#define MT_LED_CTRL_REPLAY(_n)		BIT(0 + (8 * (_n)))
#define MT_LED_CTRL_POLARITY(_n)	BIT(1 + (8 * (_n)))
#define MT_LED_CTRL_TX_BLINK_MODE(_n)	BIT(2 + (8 * (_n)))
#define MT_LED_CTRL_TX_MANUAL_BLINK(_n)	BIT(3 + (8 * (_n)))
#define MT_LED_CTRL_TX_OVER_BLINK(_n)	BIT(5 + (8 * (_n)))
#define MT_LED_CTRL_KICK(_n)		BIT(7 + (8 * (_n)))

#define MT_LED_STATUS_0(_n)		MT_LED_PHYS(0x10 + ((_n) * 8))
#define MT_LED_STATUS_1(_n)		MT_LED_PHYS(0x14 + ((_n) * 8))
#define MT_LED_STATUS_OFF		GENMASK(31, 24)
#define MT_LED_STATUS_ON		GENMASK(23, 16)
#define MT_LED_STATUS_DURATION		GENMASK(15, 0)

#define MT_PDMA_BUSY			0x82000504
#define MT_PDMA_TX_BUSY			BIT(0)
#define MT_PDMA_RX_BUSY			BIT(1)

#define MT_EFUSE_BASE			((dev)->reg_map[MT_EFUSE_ADDR_BASE])
#define MT_EFUSE_BASE_CTRL		0x000
#define MT_EFUSE_BASE_CTRL_EMPTY	BIT(30)

#define MT_EFUSE_CTRL			0x008
#define MT_EFUSE_CTRL_AOUT		GENMASK(5, 0)
#define MT_EFUSE_CTRL_MODE		GENMASK(7, 6)
#define MT_EFUSE_CTRL_LDO_OFF_TIME	GENMASK(13, 8)
#define MT_EFUSE_CTRL_LDO_ON_TIME	GENMASK(15, 14)
#define MT_EFUSE_CTRL_AIN		GENMASK(25, 16)
#define MT_EFUSE_CTRL_VALID		BIT(29)
#define MT_EFUSE_CTRL_KICK		BIT(30)
#define MT_EFUSE_CTRL_SEL		BIT(31)

#define MT_EFUSE_WDATA(_i)		(0x010 + ((_i) * 4))
#define MT_EFUSE_RDATA(_i)		(0x030 + ((_i) * 4))

/* INFRACFG host register range on MT7622 */
#define MT_INFRACFG_MISC		0x700
#define MT_INFRACFG_MISC_AP2CONN_WAKE	BIT(1)

#define MT_UMAC_BASE			0x7c000000
#define MT_UMAC(ofs)			(MT_UMAC_BASE + (ofs))
#define MT_UDMA_TX_QSEL			MT_UMAC(0x008)
#define MT_FW_DL_EN			BIT(3)

#define MT_UDMA_WLCFG_1			MT_UMAC(0x00c)
#define MT_WL_RX_AGG_PKT_LMT		GENMASK(7, 0)
#define MT_WL_TX_TMOUT_LMT		GENMASK(27, 8)

#define MT_UDMA_WLCFG_0			MT_UMAC(0x18)
#define MT_WL_RX_AGG_TO			GENMASK(7, 0)
#define MT_WL_RX_AGG_LMT		GENMASK(15, 8)
#define MT_WL_TX_TMOUT_FUNC_EN		BIT(16)
#define MT_WL_TX_DPH_CHK_EN		BIT(17)
#define MT_WL_RX_MPSZ_PAD0		BIT(18)
#define MT_WL_RX_FLUSH			BIT(19)
#define MT_TICK_1US_EN			BIT(20)
#define MT_WL_RX_AGG_EN			BIT(21)
#define MT_WL_RX_EN			BIT(22)
#define MT_WL_TX_EN			BIT(23)
#define MT_WL_RX_BUSY			BIT(30)
#define MT_WL_TX_BUSY			BIT(31)

#define MT_MCU_PTA_BASE			0x81060000
#define MT_MCU_PTA(_n)			(MT_MCU_PTA_BASE + (_n))

#define MT_ANT_SWITCH_CON(_n)		MT_MCU_PTA(0x0c8 + ((_n) - 1) * 4)
#define MT_ANT_SWITCH_CON_MODE(_n)	(GENMASK(4, 0) << (_n * 8))
#define MT_ANT_SWITCH_CON_MODE1(_n)	(GENMASK(3, 0) << (_n * 8))

#endif
