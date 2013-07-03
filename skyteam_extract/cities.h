const char* cities[] = {
    "AAA",
    "AAB",
    "AAL",
    "AAQ",
    "AAT",
    "ABA",
    "ABE",
    "ABJ",
    "ABQ",
    "ABR",
    "ABT",
    "ABV",
    "ABY",
    "ABZ",
    "ACA",
    "ACC",
    "ACE",
    "ACK",
    "ACX",
    "ADA",
    "ADB",
    "ADD",
    "ADE",
    "ADL",
    "AEP",
    "AER",
    "AES",
    "AEX",
    "AFA",
    "AGA",
    "AGF",
    "AGP",
    "AGS",
    "AGU",
    "AHB",
    "AHO",
    "AJA",
    "AJF",
    "AKL",
    "AKU",
    "ALA",
    "ALB",
    "ALC",
    "ALG",
    "ALW",
    "AMM",
    "AMS",
    "ANC",
    "ANR",
    "ANU",
    "AOI",
    "AOJ",
    "APL",
    "APN",
    "AQG",
    "AQI",
    "AQP",
    "ARH",
    "ARN",
    "ASB",
    "ASF",
    "ASR",
    "ASU",
    "ATH",
    "ATL",
    "ATW",
    "AUA",
    "AUH",
    "AUR",
    "AUS",
    "AVA",
    "AVL",
    "AVN",
    "AVP",
    "AWZ",
    "AXD",
    "AXM",
    "AXT",
    "AYT",
    "AZD",
    "AZO",
    "BAH",
    "BAQ",
    "BAV",
    "BAX",
    "BAY",
    "BCM",
    "BCN",
    "BDA",
    "BDL",
    "BDS",
    "BEG",
    "BEL",
    "BES",
    "BEY",
    "BFJ",
    "BGA",
    "BGF",
    "BGM",
    "BGO",
    "BGR",
    "BGW",
    "BGY",
    "BHD",
    "BHH",
    "BHI",
    "BHK",
    "BHM",
    "BHX",
    "BHY",
    "BIA",
    "BIL",
    "BIO",
    "BIQ",
    "BIS",
    "BJI",
    "BJM",
    "BJX",
    "BJZ",
    "BKI",
    "BKK",
    "BKO",
    "BLI",
    "BLL",
    "BLQ",
    "BLR",
    "BLZ",
    "BMI",
    "BMV",
    "BNA",
    "BND",
    "BNE",
    "BOD",
    "BOG",
    "BOI",
    "BOJ",
    "BOM",
    "BON",
    "BOS",
    "BOY",
    "BPS",
    "BQK",
    "BQS",
    "BRC",
    "BRD",
    "BRE",
    "BRI",
    "BRO",
    "BRS",
    "BRU",
    "BSB",
    "BSD",
    "BSL",
    "BTM",
    "BTR",
    "BTV",
    "BUD",
    "BUF",
    "BUR",
    "BUZ",
    "BVE",
    "BWI",
    "BZE",
    "BZN",
    "BZV",
    "CAE",
    "CAG",
    "CAH",
    "CAI",
    "CAK",
    "CAN",
    "CAY",
    "CBR",
    "CCJ",
    "CCP",
    "CCS",
    "CCU",
    "CDC",
    "CDG",
    "CEB",
    "CEI",
    "CEK",
    "CEN",
    "CFE",
    "CFU",
    "CGB",
    "CGD",
    "CGH",
    "CGK",
    "CGN",
    "CGO",
    "CGQ",
    "CGR",
    "CHA",
    "CHC",
    "CHO",
    "CHQ",
    "CHS",
    "CID",
    "CIF",
    "CIH",
    "CIU",
    "CIX",
    "CJJ",
    "CJS",
    "CJU",
    "CKG",
    "CKY",
    "CLE",
    "CLJ",
    "CLO",
    "CLT",
    "CLY",
    "CMB",
    "CME",
    "CMF",
    "CMH",
    "CMN",
    "CNF",
    "CNQ",
    "CNS",
    "CNX",
    "COD",
    "COK",
    "COO",
    "COR",
    "COS",
    "CPC",
    "CPE",
    "CPH",
    "CPQ",
    "CPR",
    "CPT",
    "CPV",
    "CRA",
    "CRC",
    "CRD",
    "CRW",
    "CSG",
    "CSX",
    "CTA",
    "CTC",
    "CTG",
    "CTS",
    "CTU",
    "CUL",
    "CUN",
    "CUR",
    "CUU",
    "CUZ",
    "CVG",
    "CWA",
    "CWB",
    "CWL",
    "CXR",
    "CZL",
    "CZM",
    "CZX",
    "DAB",
    "DAC",
    "DAD",
    "DAL",
    "DAM",
    "DAR",
    "DAT",
    "DAX",
    "DAY",
    "DBV",
    "DCA",
    "DCM",
    "DDG",
    "DEL",
    "DEN",
    "DFW",
    "DGO",
    "DHN",
    "DIG",
    "DIK",
    "DIN",
    "DJE",
    "DKR",
    "DLA",
    "DLC",
    "DLH",
    "DLI",
    "DLU",
    "DME",
    "DMM",
    "DND",
    "DNH",
    "DNK",
    "DOH",
    "DOK",
    "DOL",
    "DPS",
    "DQA",
    "DRS",
    "DSM",
    "DSN",
    "DTW",
    "DUB",
    "DUR",
    "DUS",
    "DWD",
    "DXB",
    "DYG",
    "DYU",
    "DZA",
    "EAM",
    "EAT",
    "EBB",
    "EBL",
    "ECP",
    "EDI",
    "EDL",
    "EFL",
    "EGC",
    "EGE",
    "EJH",
    "EKO",
    "ELM",
    "ELP",
    "ELQ",
    "EMA",
    "ENH",
    "ENY",
    "EQS",
    "ERI",
    "ESB",
    "ESC",
    "EUG",
    "EVN",
    "EVV",
    "EWN",
    "EWR",
    "EXT",
    "EYW",
    "EZE",
    "FAI",
    "FAO",
    "FAR",
    "FAT",
    "FAY",
    "FBM",
    "FCA",
    "FCO",
    "FDF",
    "FEG",
    "FEZ",
    "FIH",
    "FLL",
    "FLN",
    "FLR",
    "FMA",
    "FMO",
    "FNA",
    "FNT",
    "FOC",
    "FOR",
    "FPO",
    "FRA",
    "FRU",
    "FSC",
    "FSD",
    "FSM",
    "FSZ",
    "FTE",
    "FUE",
    "FUG",
    "FUK",
    "FWA",
    "GBE",
    "GBT",
    "GCC",
    "GCI",
    "GCM",
    "GDL",
    "GDX",
    "GDZ",
    "GEG",
    "GFK",
    "GGT",
    "GIG",
    "GIZ",
    "GJT",
    "GLA",
    "GMP",
    "GNB",
    "GND",
    "GNV",
    "GOA",
    "GOI",
    "GOJ",
    "GOQ",
    "GOT",
    "GPT",
    "GRB",
    "GRK",
    "GRO",
    "GRR",
    "GRU",
    "GRX",
    "GSO",
    "GSP",
    "GTF",
    "GTR",
    "GUA",
    "GUM",
    "GVA",
    "GYD",
    "GYE",
    "GYN",
    "HAH",
    "HAJ",
    "HAK",
    "HAM",
    "HAN",
    "HAS",
    "HAV",
    "HBE",
    "HDG",
    "HDN",
    "HEK",
    "HEL",
    "HER",
    "HET",
    "HFE",
    "HGH",
    "HIA",
    "HIB",
    "HIJ",
    "HIN",
    "HJJ",
    "HKD",
    "HKG",
    "HKT",
    "HLD",
    "HLN",
    "HMI",
    "HMO",
    "HND",
    "HNL",
    "HOF",
    "HOU",
    "HPH",
    "HPN",
    "HRB",
    "HRE",
    "HRK",
    "HSN",
    "HSV",
    "HTA",
    "HTN",
    "HUI",
    "HUX",
    "HUY",
    "HYD",
    "HYN",
    "HZH",
    "IAD",
    "IAH",
    "IAS",
    "IBZ",
    "ICN",
    "ICT",
    "IDA",
    "IFN",
    "IGR",
    "IGU",
    "IKA",
    "IKT",
    "ILM",
    "IMT",
    "INC",
    "IND",
    "INL",
    "INN",
    "INV",
    "IOM",
    "IRJ",
    "ISB",
    "ISN",
    "IST",
    "ITH",
    "ITM",
    "ITO",
    "IVL",
    "JAC",
    "JAN",
    "JAX",
    "JDZ",
    "JED",
    "JER",
    "JFK",
    "JGN",
    "JGS",
    "JHG",
    "JIB",
    "JIQ",
    "JIU",
    "JJN",
    "JKH",
    "JMK",
    "JMU",
    "JNB",
    "JNG",
    "JNU",
    "JNZ",
    "JOE",
    "JPA",
    "JRO",
    "JTR",
    "JUB",
    "JUJ",
    "JUL",
    "JXA",
    "JZH",
    "KAN",
    "KAO",
    "KBP",
    "KCA",
    "KCH",
    "KEF",
    "KEJ",
    "KGD",
    "KGF",
    "KGL",
    "KGS",
    "KGT",
    "KHG",
    "KHH",
    "KHI",
    "KHN",
    "KHV",
    "KIJ",
    "KIN",
    "KIS",
    "KIV",
    "KIX",
    "KJA",
    "KJI",
    "KLV",
    "KMC",
    "KMG",
    "KMI",
    "KMJ",
    "KMQ",
    "KOA",
    "KOJ",
    "KOW",
    "KPO",
    "KRK",
    "KRL",
    "KRR",
    "KRS",
    "KRT",
    "KRY",
    "KSC",
    "KSQ",
    "KTM",
    "KTN",
    "KTT",
    "KUF",
    "KUL",
    "KUO",
    "KUV",
    "KWE",
    "KWI",
    "KWJ",
    "KWL",
    "KZN",
    "LAD",
    "LAI",
    "LAN",
    "LAP",
    "LAS",
    "LAX",
    "LBA",
    "LBD",
    "LBV",
    "LCA",
    "LCG",
    "LCX",
    "LCY",
    "LDB",
    "LDE",
    "LDS",
    "LED",
    "LEN",
    "LEX",
    "LFT",
    "LFW",
    "LGA",
    "LGB",
    "LGK",
    "LGS",
    "LGW",
    "LHE",
    "LHR",
    "LHW",
    "LIG",
    "LIH",
    "LIL",
    "LIM",
    "LIN",
    "LIR",
    "LIS",
    "LIT",
    "LJG",
    "LJU",
    "LKO",
    "LLB",
    "LLF",
    "LLW",
    "LMM",
    "LMP",
    "LNJ",
    "LNK",
    "LOS",
    "LPA",
    "LPI",
    "LPQ",
    "LRD",
    "LRH",
    "LRT",
    "LSE",
    "LTO",
    "LUM",
    "LUN",
    "LUQ",
    "LUX",
    "LVI",
    "LWO",
    "LWS",
    "LXA",
    "LXR",
    "LYA",
    "LYG",
    "LYI",
    "LYS",
    "LZH",
    "LZO",
    "MAA",
    "MAD",
    "MAH",
    "MAM",
    "MAN",
    "MAO",
    "MBA",
    "MBJ",
    "MBS",
    "MCI",
    "MCO",
    "MCP",
    "MCT",
    "MCZ",
    "MDE",
    "MDG",
    "MDL",
    "MDQ",
    "MDT",
    "MDW",
    "MDZ",
    "MED",
    "MEL",
    "MEM",
    "MEX",
    "MFM",
    "MFR",
    "MGA",
    "MGF",
    "MGM",
    "MHD",
    "MHT",
    "MIA",
    "MID",
    "MIG",
    "MJT",
    "MKE",
    "MLA",
    "MLB",
    "MLE",
    "MLH",
    "MLI",
    "MLM",
    "MLU",
    "MME",
    "MMH",
    "MMK",
    "MNL",
    "MOB",
    "MOT",
    "MPL",
    "MPM",
    "MQF",
    "MQT",
    "MRS",
    "MRU",
    "MRV",
    "MSE",
    "MSN",
    "MSO",
    "MSP",
    "MSQ",
    "MSY",
    "MTJ",
    "MTT",
    "MTY",
    "MUC",
    "MVD",
    "MVY",
    "MWX",
    "MWZ",
    "MXL",
    "MXP",
    "MXZ",
    "MYD",
    "MYJ",
    "MYR",
    "MYY",
    "MZT",
    "NAN",
    "NAO",
    "NAP",
    "NAS",
    "NAT",
    "NBC",
    "NBO",
    "NBS",
    "NCE",
    "NCL",
    "NDG",
    "NDJ",
    "NGB",
    "NGO",
    "NGQ",
    "NGS",
    "NIM",
    "NJC",
    "NJF",
    "NKC",
    "NKG",
    "NLA",
    "NLD",
    "NLT",
    "NMA",
    "NNG",
    "NNY",
    "NOU",
    "NOZ",
    "NQN",
    "NRT",
    "NSI",
    "NSK",
    "NTE",
    "NTG",
    "NUE",
    "NVI",
    "NVT",
    "NWI",
    "NYT",
    "NZH",
    "OAJ",
    "OAK",
    "OAX",
    "ODS",
    "OGG",
    "OHE",
    "OIT",
    "OKA",
    "OKC",
    "OKJ",
    "OLB",
    "OMA",
    "OMH",
    "OMR",
    "OMS",
    "ONT",
    "OOL",
    "OPO",
    "ORD",
    "ORF",
    "ORK",
    "ORN",
    "ORY",
    "OSL",
    "OSR",
    "OSS",
    "OTP",
    "OUA",
    "OUD",
    "OUL",
    "OVB",
    "OVD",
    "PAD",
    "PAP",
    "PAZ",
    "PBC",
    "PBI",
    "PBM",
    "PDP",
    "PDX",
    "PEE",
    "PEI",
    "PEK",
    "PEM",
    "PEN",
    "PER",
    "PEW",
    "PFO",
    "PGF",
    "PHC",
    "PHF",
    "PHL",
    "PHX",
    "PIA",
    "PIH",
    "PIT",
    "PKC",
    "PLN",
    "PLS",
    "PLZ",
    "PMC",
    "PMI",
    "PMO",
    "PNA",
    "PNH",
    "PNL",
    "PNR",
    "PNS",
    "POA",
    "POL",
    "PPE",
    "PPT",
    "PQC",
    "PRG",
    "PSA",
    "PSC",
    "PSP",
    "PSR",
    "PSS",
    "PTP",
    "PTY",
    "PUF",
    "PUJ",
    "PUQ",
    "PUS",
    "PUW",
    "PVD",
    "PVG",
    "PVR",
    "PWM",
    "PWQ",
    "PXU",
    "QRO",
    "RAE",
    "RAH",
    "RAK",
    "RAP",
    "RAS",
    "RBA",
    "RDM",
    "RDU",
    "RDZ",
    "REC",
    "REG",
    "REL",
    "REN",
    "REP",
    "RES",
    "REX",
    "RGA",
    "RGL",
    "RGN",
    "RHD",
    "RHI",
    "RHO",
    "RIC",
    "RIX",
    "RKS",
    "RMQ",
    "RNO",
    "RNS",
    "ROA",
    "ROB",
    "ROC",
    "ROR",
    "ROS",
    "ROV",
    "RSA",
    "RST",
    "RSU",
    "RSW",
    "RTB",
    "RTM",
    "RUH",
    "RUN",
    "RVN",
    "SAH",
    "SAL",
    "SAN",
    "SAP",
    "SAT",
    "SAV",
    "SAW",
    "SBN",
    "SBZ",
    "SCE",
    "SCL",
    "SCQ",
    "SCV",
    "SCW",
    "SDE",
    "SDF",
    "SDQ",
    "SDU",
    "SEA",
    "SEZ",
    "SFN",
    "SFO",
    "SGC",
    "SGF",
    "SGN",
    "SGU",
    "SHA",
    "SHE",
    "SHJ",
    "SHP",
    "SHV",
    "SHW",
    "SIN",
    "SIP",
    "SIT",
    "SJC",
    "SJD",
    "SJO",
    "SJU",
    "SJW",
    "SKB",
    "SKD",
    "SKG",
    "SLA",
    "SLC",
    "SLM",
    "SLP",
    "SLU",
    "SLW",
    "SLZ",
    "SMF",
    "SMI",
    "SNA",
    "SNN",
    "SOF",
    "SOU",
    "SPN",
    "SPU",
    "SRQ",
    "SSA",
    "SSG",
    "SSH",
    "STI",
    "STL",
    "STM",
    "STR",
    "STS",
    "STT",
    "STW",
    "SUB",
    "SUF",
    "SUJ",
    "SUN",
    "SVG",
    "SVO",
    "SVQ",
    "SVX",
    "SWA",
    "SWF",
    "SXB",
    "SXF",
    "SXM",
    "SYD",
    "SYM",
    "SYR",
    "SYX",
    "SYZ",
    "SZG",
    "SZX",
    "TAE",
    "TAK",
    "TAM",
    "TAO",
    "TAP",
    "TAS",
    "TBB",
    "TBS",
    "TBZ",
    "TCQ",
    "TCZ",
    "TDX",
    "TEN",
    "TFN",
    "TFS",
    "TGD",
    "TGM",
    "TGO",
    "TGU",
    "TGZ",
    "THD",
    "THE",
    "THR",
    "THS",
    "TIA",
    "TIF",
    "TIJ",
    "TIP",
    "TIV",
    "TJM",
    "TKU",
    "TLC",
    "TLH",
    "TLL",
    "TLN",
    "TLS",
    "TLV",
    "TMP",
    "TNA",
    "TNG",
    "TNN",
    "TNR",
    "TOF",
    "TOY",
    "TPA",
    "TPE",
    "TPS",
    "TRC",
    "TRD",
    "TRF",
    "TRI",
    "TRN",
    "TRS",
    "TRU",
    "TSA",
    "TSE",
    "TSN",
    "TSR",
    "TUC",
    "TUI",
    "TUL",
    "TUN",
    "TUS",
    "TUU",
    "TVC",
    "TVS",
    "TWF",
    "TXL",
    "TXN",
    "TYN",
    "TYS",
    "TZX",
    "UAQ",
    "UFA",
    "UGC",
    "UIH",
    "UIO",
    "UIP",
    "UKK",
    "ULH",
    "ULN",
    "URC",
    "URY",
    "USH",
    "USM",
    "USN",
    "UUD",
    "UUS",
    "UVF",
    "UYN",
    "VAA",
    "VAR",
    "VCA",
    "VCE",
    "VCL",
    "VCS",
    "VDA",
    "VDH",
    "VDM",
    "VER",
    "VGO",
    "VIE",
    "VII",
    "VIX",
    "VKG",
    "VKO",
    "VLC",
    "VLD",
    "VLL",
    "VNO",
    "VOG",
    "VPS",
    "VRN",
    "VSA",
    "VTE",
    "VVI",
    "VVO",
    "WAE",
    "WAW",
    "WDH",
    "WEF",
    "WEH",
    "WJU",
    "WLG",
    "WNH",
    "WNZ",
    "WUA",
    "WUH",
    "WUS",
    "WUX",
    "WXN",
    "WYS",
    "XFN",
    "XIL",
    "XIY",
    "XMN",
    "XNA",
    "XNN",
    "XUZ",
    "YBP",
    "YCU",
    "YDF",
    "YEG",
    "YHZ",
    "YIH",
    "YIN",
    "YIW",
    "YKA",
    "YKM",
    "YKS",
    "YLW",
    "YMM",
    "YNB",
    "YNJ",
    "YNT",
    "YNZ",
    "YOW",
    "YQB",
    "YQG",
    "YQM",
    "YQQ",
    "YQR",
    "YQT",
    "YQU",
    "YQY",
    "YTY",
    "YUL",
    "YUS",
    "YVR",
    "YWG",
    "YXE",
    "YXS",
    "YXX",
    "YYC",
    "YYG",
    "YYJ",
    "YYT",
    "YYZ",
    "ZAG",
    "ZAH",
    "ZAT",
    "ZAZ",
    "ZCL",
    "ZHA",
    "ZHY",
    "ZIH",
    "ZLO",
    "ZNZ",
    "ZRH",
    "ZSE",
    "ZUH",
    "ZYI"
};

